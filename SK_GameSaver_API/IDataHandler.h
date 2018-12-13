#pragma once
#include "ByteStream.h"
#include <memory>

class IDataHandler
{
public:
	IDataHandler();
	virtual ~IDataHandler();

	virtual bool Serialize(const int& value) = 0;
	virtual bool Deserialize(int& value) = 0;
protected:
	std::shared_ptr<ByteStream> m_byteStream;
};

