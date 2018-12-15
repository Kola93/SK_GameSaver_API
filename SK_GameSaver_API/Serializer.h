#pragma once
#include "IDataHandler.h"
#include <memory>

class Serializer : public IDataHandler
{
public:
	Serializer() = delete;
	Serializer(std::shared_ptr<ByteStream> p_byteStream);
	~Serializer();

	bool Serialize(const int& value) override;
	bool Serialize(const float& value) override;
	bool Serialize(const bool& value) override;
	//bool Serialize(const std::string& value) 

private:
};

