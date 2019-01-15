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
	m_generateLogFile = false;
}

void GameSaver::SetGenerateLogFileActive()
{
	m_generateLogFile = true;
}

SaveandLoad_Result GameSaver::Save(ISerializable& p_serializable)
{
	const auto xByteStream_ptr = std::make_shared<ByteStream>();
	const auto xSerializer_ptr = std::make_shared<Serializer>(xByteStream_ptr);
	
	if(!p_serializable.Serialize(xSerializer_ptr))
	{
		return FAILED_COULD_NOT_SERIALIZE_YOUR_DATA;
	}
	xByteStream_ptr->DeleteEmptySpace();

	std::string completeDirectory = m_FIlePath + m_FIleName + m_FIleExtension;
	std::ofstream outfile(completeDirectory, std::ios::binary);
	if(!outfile.is_open())
	{
		return FAILED_COULD_NOT_CREATE_FILE_IN_DIRECTORY;
	}
	outfile.write(xByteStream_ptr->GetBuffer(), xByteStream_ptr->GetSize());
	outfile.close();

	if(m_generateLogFile)
	{
		auto xLogHistory = xByteStream_ptr->GetSaveHistory();

		std::ofstream outfile_debug(m_FIlePath + m_FIleName + "_debug.log", std::ios::out);
		if (!outfile_debug.is_open())
		{
			return FAILED_COULD_NOT_CREATE_LOG_FILE_IN_DIRECTORY;
		}
		for (int i = 0; i < xLogHistory.size(); ++i)
		{
			outfile_debug << xLogHistory[i] << std::endl;
		}
		outfile_debug.close();
	}

	return SUCCESS;
}

SaveandLoad_Result GameSaver::Load(ISerializable& p_serializable)
{	
	std::ifstream infile(m_FIlePath + m_FIleName + m_FIleExtension, std::ios::binary);
	if(!infile.is_open())
	{
		return FAILED_COULD_NOT_OPEN_FILE_IN_DIRECTORY;
	}
	infile.seekg(0, infile.end);
	int length = static_cast<int>(infile.tellg());
	infile.seekg(0, infile.beg);

	if(length <= 0)
	{
		return FAILED_FILE_IS_EMPTY;
	}
	const auto xByteStream_ptr = std::make_shared<ByteStream>(length);
	const auto xDeserializer_ptr = std::make_shared<Deserializer>(xByteStream_ptr);

	infile.read(xByteStream_ptr->GetBuffer(), xByteStream_ptr->GetSize());
	if(!p_serializable.Deserialize(xDeserializer_ptr))
	{
		return FAILED_COULD_NOT_DESERIALIZE_YOUR_DATA;
	}		
	infile.close();	

	return SUCCESS;
}

