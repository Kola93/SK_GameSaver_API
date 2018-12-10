#pragma once
#include "IDataHandler.h"

class Serializer : public IDataHandler
{
public:
	Serializer();
	~Serializer();

	bool Serialize(const int& value) override;
};

