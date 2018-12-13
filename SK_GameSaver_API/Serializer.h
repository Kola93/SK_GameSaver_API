#pragma once
#include "IDataHandler.h"
#include <memory>

class Serializer : public IDataHandler
{
public:
	Serializer(std::shared_ptr<ByteStream> p_byteStream);
	~Serializer();

	bool Serialize(const int& value) override;
	bool Deserialize(int& value) override { return true; };
private:
};

