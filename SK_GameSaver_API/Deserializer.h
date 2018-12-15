#pragma once
#include <memory>
#include "ByteStream.h"
#include <string>
class Deserializer 
{
public:
	Deserializer() = delete;
	Deserializer(std::shared_ptr<ByteStream> p_byteStream);
	~Deserializer();
	
	virtual bool Deserialize(int& value);
	virtual bool Deserialize(float& value);
	virtual bool Deserialize(double& value);
	virtual bool Deserialize(bool& value);
	virtual bool Deserialize(char& value);
	virtual bool Deserialize(int count, std::string& value);
private:
	std::shared_ptr<ByteStream> m_byteStream;
};

