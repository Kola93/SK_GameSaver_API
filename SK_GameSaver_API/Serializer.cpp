#include "Serializer.h"



Serializer::Serializer(std::shared_ptr<ByteStream> p_byteStream)
{
	m_byteStream = p_byteStream;
}


Serializer::~Serializer()
{
}

bool Serializer::Serialize(const int& value)
{
	m_byteStream->Write(value);

	return true;
}
