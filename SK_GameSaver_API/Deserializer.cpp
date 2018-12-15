#include "Deserializer.h"
#include "Serializer.h"




Deserializer::Deserializer(std::shared_ptr<ByteStream> p_byteStream)
{
	m_byteStream = p_byteStream;
}


Deserializer::~Deserializer()
{
}


bool Deserializer::Deserialize(int& value)
{
	if (m_byteStream->Read(value))
	{
		return true;
	}
	return false;
}

bool Deserializer::Deserialize(float & value)
{
	if (m_byteStream->Read(value))
	{
		return true;
	}
	return false;
}

bool Deserializer::Deserialize(bool & value)
{
	if (m_byteStream->Read(value))
	{
		return true;
	}
	return false;
}