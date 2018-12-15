#pragma once
#include "IDataHandler.h"

class Deserializer : public IDataHandler
{
public:
	Deserializer() = delete;
	Deserializer(std::shared_ptr<ByteStream> p_byteStream);
	~Deserializer();
	
	bool Deserialize(int& value) override;
	bool Deserialize(float& value) override;
	bool Deserialize(bool& value) override;

private:
};

