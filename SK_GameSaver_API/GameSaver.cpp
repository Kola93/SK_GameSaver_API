#include "GameSaver.h"
#include "ByteStream.h"
#include "ISerializable.h"
#include <fstream>
#include <iostream>
#include "Deserializer.h"

GameSaver::GameSaver(std::string p_FilePath, std::string p_FileName, std::string p_extension)
{
	m_FIlePath = p_FilePath;
	m_FIleName = p_FileName;
	m_FIleExtension = p_extension;
	m_FullFilePath = m_FIlePath + m_FIleName + m_FIleExtension;
	m_generateLogFile = false;
}

GameSaver::GameSaver(std::string p_FilePath)
{
	m_FullFilePath = p_FilePath;
	m_generateLogFile = false;
}

void GameSaver::SetGenerateLogFileActive()
{
	m_generateLogFile = true;
}

bool GameSaver::GenerateFileLog(const std::shared_ptr<ByteStream> xByteStream_ptr)
{
	auto xLogHistory = xByteStream_ptr->GetSaveHistory();

	std::ofstream outfile_debug(m_FullFilePath + "_debug.log", std::ios::out);
	if (!outfile_debug.is_open())
	{
		throw std::exception("Error: counldn't create log file in the specified path, make sure the path is correct!");
	}
	for (size_t i = 0; i < xLogHistory.size(); ++i)
	{
		outfile_debug << xLogHistory[i] << std::endl;
	}
	outfile_debug.close();
	return true;
}

bool GameSaver::Save(ISerializable& p_serializable)
{
	const auto xByteStream_ptr = std::make_shared<ByteStream>();
	const auto xSerializer_ptr = std::make_shared<Serializer>(xByteStream_ptr);
	
	if(!p_serializable.Serialize(xSerializer_ptr))
	{
		throw std::exception("Error: counldn't serialize your data!");
	}
	xByteStream_ptr->DeleteEmptySpace();

	std::ofstream outfile(m_FullFilePath, std::ios::binary);
	if(!outfile.is_open())
	{
		throw std::exception("Error: counldn't create file in the specified path, make sure the path is correct!");
	}
	outfile.write(xByteStream_ptr->GetBuffer(), xByteStream_ptr->GetSize());
	outfile.close();

	if(m_generateLogFile)
	{
		return GenerateFileLog(xByteStream_ptr);
	}

	return true;
}

bool GameSaver::Load(ISerializable* p_serializable)
{	
	std::ifstream infile(m_FullFilePath, std::ios::binary);
	if(!infile.is_open())
	{
		throw std::exception("Error: the file couln't be loaded. File not found in the path specified");
	}
	infile.seekg(0, infile.end);
	int length = static_cast<int>(infile.tellg());
	infile.seekg(0, infile.beg);

	if(length <= 0)
	{
		throw std::exception("Error: the file loaded is empty!");
	}
	const auto xByteStream_ptr = std::make_shared<ByteStream>(length);
	const auto xDeserializer_ptr = std::make_shared<Deserializer>(xByteStream_ptr);

	infile.read(xByteStream_ptr->GetBuffer(), xByteStream_ptr->GetSize());
	if(!p_serializable->Deserialize(xDeserializer_ptr))
	{
		throw std::exception("Error: counldn't deserialize your data!");
	}		
	infile.close();	

	return true;
}

