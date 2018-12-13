#pragma once

#include "Serializer.h"
#include "Deserializer.h"
class ISerializable
{
public:
	ISerializable();
	virtual ~ISerializable();

	virtual bool Serialize(Serializer* p_serializer) = 0;
	virtual bool Deserialize(Deserializer* p_serializer) = 0;
};

