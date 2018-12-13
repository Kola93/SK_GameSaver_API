#pragma once
#include "IDataHandler.h"

class Deserializer : public IDataHandler
{
public:
	Deserializer(ByteStream* p_byteStream);
	~Deserializer();

	bool Serialize(const int& value) override { return true; };
	bool Deserialize(int& value) override;

private:
};

