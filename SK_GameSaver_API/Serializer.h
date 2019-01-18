#pragma once
#include <memory>
#include "ByteStream.h"
#include <string>
class Serializer 
{
public:
	Serializer() = delete;
	Serializer(std::shared_ptr<ByteStream> p_byteStream);
	~Serializer() = default;

	virtual bool Serialize(const int& value);
	virtual bool Serialize(const float& value);
	virtual bool Serialize(const double& value);
	virtual bool Serialize(const bool& value);
	virtual bool Serialize(const char& value);
	virtual bool Serialize(const int& length, const std::string& value);
	template <class T>
	bool Serialize(const int& length, const T* value);
private:
	std::shared_ptr<ByteStream> m_byteStream;
};

template<class T>
inline bool Serializer::Serialize(const int &length, const T* value)
{
	for (int i = 0; i < length; ++i)
	{	
		if (!Serialize(value[i]))
		{
			return false;
		}		
	}
	return true;
}
