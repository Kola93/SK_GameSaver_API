#pragma once
#include "ISerializable.h"


struct UserTest : public ISerializable
{
	int health;
	int life;
	bool Serialize(std::shared_ptr<Serializer> p_serializer) override
	{
		if (!p_serializer->Serialize(health))
			return false;
		if (!p_serializer->Serialize(life))
			return false;
		return true;
	}
	bool Deserialize(std::shared_ptr<Deserializer> p_deserializer) override
	{

		if (!p_deserializer->Deserialize(health))
			return false;
		if (!p_deserializer->Deserialize(life))
			return false;
		return true;
	}
};
