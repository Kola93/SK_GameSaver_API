#pragma once
#include "ISerializable.h"


class  UserTest : public ISerializable
{
public:
	int health = 0;
	int life = 0;
	UserTest() {};
	~UserTest() {};
	bool ISerializable::Serialize(std::shared_ptr<Serializer> p_serializer) override
	{
		if (!p_serializer->Serialize(health))
			return false;
		if (!p_serializer->Serialize(life))
			return false;
		return true;
	}
	bool  ISerializable::Deserialize(std::shared_ptr<Deserializer> p_deserializer) override
	{

		if (!p_deserializer->Deserialize(health))
			return false;
		if (!p_deserializer->Deserialize(life))
			return false;
		return true;
	}
};
