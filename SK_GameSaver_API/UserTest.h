#pragma once
#include "ISerializable.h"


class  UserTest : public ISerializable
{
public:
	int health = 0;
	int life = 0;
	UserTest();;
	~UserTest();
	bool Serialize(std::shared_ptr<Serializer> p_serializer) override;
	
	bool  Deserialize(std::shared_ptr<Deserializer> p_deserializer) override;
};
