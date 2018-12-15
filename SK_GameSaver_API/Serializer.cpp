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
	if(m_byteStream->Write(value))
	{
		return true;
	}
	return false;
}


bool Serializer::Serialize(const float & value)
{
	if (m_byteStream->Write(value))
	{
		return true;
	}
	return false;
}

bool Serializer::Serialize(const bool & value)
{
	if (m_byteStream->Write(value))
	{
		return true;
	}
	return false;
}
