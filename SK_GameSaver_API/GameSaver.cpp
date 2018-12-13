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
	ByteStream* xByteStream = new ByteStream();
	Serializer* xSerializer = new Serializer(xByteStream);
	
	p_serializable.Serialize(xSerializer);

	std::ofstream ofile("foobar.txt", std::ios::out);
	std::cout << xByteStream->GetBuffer()[0];

	ofile.write(reinterpret_cast<char*>(&xByteStream->GetBuffer()[0]), xByteStream->GetSize());
	ofile.close();
}

void GameSaver::Load(ISerializable& p_serializable)
{	

	std::ifstream ifile("foobar.txt", std::ios::in);
	ifile.seekg(0, ifile.end);
	int length = ifile.tellg();
	ifile.seekg(0, ifile.beg);
	unsigned char* buffer2 = new unsigned char[length];



	ByteStream* xByteStream = new ByteStream(length);
	Deserializer* xDeserializer = new Deserializer(xByteStream);

	ifile.read(reinterpret_cast<char*>(&xByteStream->GetBuffer()[0]), xByteStream->GetSize());
	p_serializable.Deserialize(xDeserializer);
}

