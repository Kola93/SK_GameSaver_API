#pragma once
#include <memory>
#include "ByteStream.h"
#include <string>
class Deserializer 
{
public:
	Deserializer() = delete;
	Deserializer(std::shared_ptr<ByteStream> p_byteStream);
	~Deserializer() = default;
	
	virtual bool Deserialize(int& value);
	virtual bool Deserialize(float& value);
	virtual bool Deserialize(double& value);
	virtual bool Deserialize(bool& value);
	virtual bool Deserialize(char& value);
	virtual bool Deserialize(int length, std::string& value);
	template <class T>
	bool Deserialize(const int& length, T& value);
private:
	std::shared_ptr<ByteStream> m_byteStream;
};

template<class T>
inline bool Deserializer::Deserialize(const int &length, T& value)
{
	for (int i = 0; i < length; ++i)
	{
		if (!Deserialize(value[i]))
		{
			return false;
		}
	}
	return true;
}
