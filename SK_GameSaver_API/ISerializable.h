#pragma once

#include "Serializer.h"
#include "Deserializer.h"
class ISerializable
{
public:
	ISerializable();
	virtual ~ISerializable();

	virtual bool Serialize(std::shared_ptr<Serializer> p_serializer) = 0;
	virtual bool Deserialize(std::shared_ptr<Deserializer> p_deserializer) = 0;
};

