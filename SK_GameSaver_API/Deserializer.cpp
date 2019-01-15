#include "Deserializer.h"
#include "Serializer.h"




Deserializer::Deserializer(std::shared_ptr<ByteStream> p_byteStream)
{
	m_byteStream = p_byteStream;
}


bool Deserializer::Deserialize(int& value)
{
	return m_byteStream->Read(value);
}

bool Deserializer::Deserialize(float & value)
{
	return m_byteStream->Read(value);
}

bool Deserializer::Deserialize(double & value)
{
	return m_byteStream->Read(value);
}

bool Deserializer::Deserialize(bool & value)
{
	return m_byteStream->Read(value);
}

bool Deserializer::Deserialize(char & value)
{
	return m_byteStream->Read(value);
}

bool Deserializer::Deserialize(int length, std::string & value)
{
	return m_byteStream->Read(length, value);
}

