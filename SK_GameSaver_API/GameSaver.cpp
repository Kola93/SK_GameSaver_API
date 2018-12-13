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
	//Serializer* xSerializer = new Serializer(xByteStream_ptr);
	
	p_serializable.Serialize(xSerializer_ptr);

	std::ofstream ofile("foobar.txt", std::ios::out);

	ofile.write(reinterpret_cast<char*>(&xByteStream_ptr->GetBuffer()[0]), xByteStream_ptr->GetSize());
	ofile.close();
}

void GameSaver::Load(ISerializable& p_serializable)
{	

	std::ifstream ifile("foobar.txt", std::ios::in);
	ifile.seekg(0, ifile.end);
	int length = ifile.tellg();
	ifile.seekg(0, ifile.beg);
	//unsigned char* buffer2 = new unsigned char[length];



	auto xByteStream_ptr = std::make_shared<ByteStream>(length);
	const auto xDeserializer_ptr = std::make_shared<Deserializer>(xByteStream_ptr);

	ifile.read(reinterpret_cast<char*>(&xByteStream_ptr->GetBuffer()[0]), xByteStream_ptr->GetSize());
	p_serializable.Deserialize(xDeserializer_ptr);
	ifile.close();
}

