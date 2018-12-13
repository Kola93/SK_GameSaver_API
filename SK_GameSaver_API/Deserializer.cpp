#include "Deserializer.h"



Deserializer::Deserializer( ByteStream* p_byteStream)
{
	m_byteStream = p_byteStream;
}


Deserializer::~Deserializer()
{
}

bool Deserializer::Deserialize(int& value)
{
	m_byteStream->Read(value);

	return true;
}
