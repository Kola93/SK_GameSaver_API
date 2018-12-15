#pragma once
#include <memory>
#include "ByteStream.h"
#include <string>
class Serializer 
{
public:
	Serializer() = delete;
	Serializer(std::shared_ptr<ByteStream> p_byteStream);
	~Serializer();

	virtual bool Serialize(const int& value);
	virtual bool Serialize(const float& value);
	virtual bool Serialize(const double& value);
	virtual bool Serialize(const bool& value);
	virtual bool Serialize(int count, const std::string& value);
	virtual bool Serialize(const char& value);
private:
	std::shared_ptr<ByteStream> m_byteStream;
};

