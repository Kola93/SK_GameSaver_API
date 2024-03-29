#include "Serializer.h"

Serializer::Serializer(std::shared_ptr<ByteStream> p_byteStream)
{
	m_byteStream = p_byteStream;
}

bool Serializer::Serialize(const int& value)
{
	return m_byteStream->Write(value);
}

bool Serializer::Serialize(const float & value)
{
	return m_byteStream->Write(value);
}

bool Serializer::Serialize(const double & value)
{
	return m_byteStream->Write(value);
}

bool Serializer::Serialize(const bool & value)
{
	return m_byteStream->Write(value);
}
bool Serializer::Serialize(const int& length, const std::string & value)
{
	return m_byteStream->Write(length, value);
}
bool Serializer::Serialize(const char & value)
{
	return m_byteStream->Write(value);
}