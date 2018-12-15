#pragma once
#include "IDataHandler.h"

class Deserializer : public IDataHandler
{
public:
	Deserializer();
	Deserializer(std::shared_ptr<ByteStream> p_byteStream);
	~Deserializer();
	bool Serialize(const int& value) override { return true; };
	bool Serialize(const float& value) override { return true; };
	bool Serialize(const bool& value) override{ return true; };
	bool Deserialize(int& value) override;
	bool Deserialize(float& value) override;
	bool Deserialize(bool& value) override;

private:
};

