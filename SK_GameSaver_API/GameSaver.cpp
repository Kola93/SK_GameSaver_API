#include "GameSaver.h"
#include "ByteStream.h"
#include "ISerializable.h"
#include <fstream>
#include <iostream>
#include "Deserializer.h"
#include "UserTest.h"


GameSaver::GameSaver(std::string p_path)
{
	m_path = p_path;
}


GameSaver::~GameSaver()
{
}

void GameSaver::Save( ISerializable& p_serializable)
{
	auto xByteStream_ptr = std::make_shared<ByteStream>();
	const auto xSerializer_ptr = std::make_shared<Serializer>(xByteStream_ptr);
	
	if(!p_serializable.Serialize(xSerializer_ptr))
	{
		
	}

	std::ofstream outfile(m_path, std::ios::out);
	if(!outfile.is_open())
	{
		//TODO: EXCEPTION		
	}
	else
	{
		outfile.write(&xByteStream_ptr->GetBuffer()[0], xByteStream_ptr->GetSize());
		outfile.close();
	}	
}

void GameSaver::Load(ISerializable& p_serializable)
{	
	std::ifstream infile(m_path, std::ios::in);
	if(!infile.is_open())
	{
		//TODO: EXCEPTION
	}
	else
	{
		infile.seekg(0, infile.end);
		int length = static_cast<int>(infile.tellg());
		infile.seekg(0, infile.beg);
		// TODO CHECK IF LENGHT != -1
		if(length <= 0)
		{
			// TODO: EXCEPTION
		}
		auto xByteStream_ptr = std::make_shared<ByteStream>(length);
		const auto xDeserializer_ptr = std::make_shared<Deserializer>(xByteStream_ptr);

		infile.read(&xByteStream_ptr->GetBuffer()[0], xByteStream_ptr->GetSize());
		p_serializable.Deserialize(xDeserializer_ptr);
		infile.close();
	}

	
}

