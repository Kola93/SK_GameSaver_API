#pragma once
#include "IDataHandler.h"

class Serializer : public IDataHandler
{
public:
	Serializer(ByteStream* p_byteStream);
	~Serializer();

	bool Serialize(const int& value) override;
	bool Deserialize(int& value) override { return true; };
private:
};

