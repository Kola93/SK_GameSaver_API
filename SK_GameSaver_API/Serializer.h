#pragma once
#include "IDataHandler.h"
#include <memory>

class Serializer : public IDataHandler
{
public:
	Serializer();
	Serializer(std::shared_ptr<ByteStream> p_byteStream);
	~Serializer();

	bool Serialize(const int& value) override;
	bool Serialize(const float& value) override;
	bool Serialize(const bool& value) override;

	bool Deserialize(int& value) override { return true; };
	bool Deserialize(float& value) override { return true; };
	bool Deserialize(bool& value) override { return true; };
private:
};

