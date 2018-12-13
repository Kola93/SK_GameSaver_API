#pragma once
#include "ISerializable.h"


struct UserTest : public ISerializable
{
	int health;
	int life;
	bool Serialize(Serializer* p_serializer) override
	{
		if (!p_serializer->Serialize(health))
			return false;
		if (!p_serializer->Serialize(life))
			return false;
		return true;
	}
	bool Deserialize(Deserializer* p_serializer) override
	{

		if (!p_serializer->Deserialize(health))
			return false;
		if (!p_serializer->Deserialize(life))
			return false;
		return true;
	}
};
