#pragma once
#include "ByteStream.h"

class IDataHandler
{
public:
	IDataHandler();
	virtual ~IDataHandler();

	virtual bool Serialize(const int& value) = 0;
	virtual bool Deserialize(int& value) = 0;
protected:
	ByteStream* m_byteStream;
};

