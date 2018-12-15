#pragma once
#include "ByteStream.h"
#include <memory>

class IDataHandler
{
public:
	IDataHandler();
	virtual ~IDataHandler();

	virtual bool Serialize(const int& value) { return false; };
	virtual bool Serialize(const float& value) { return false; };
	virtual bool Serialize(const bool& value) { return false; };

	virtual bool Deserialize(int& value) { return false; };
	virtual bool Deserialize(float& value) { return false; };
	virtual bool Deserialize(bool& value) { return false; };
protected:
	std::shared_ptr<ByteStream> m_byteStream;
};

