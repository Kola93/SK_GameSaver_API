#include "UserTest.h"

UserTest::UserTest()
{
}

UserTest::~UserTest()
{
}

bool UserTest::Serialize(std::shared_ptr<Serializer> p_serializer)
{
	
	if (!p_serializer->Serialize(health))
		return false;
	if (!p_serializer->Serialize(life))
		return false;
	return true;
	
}

bool UserTest::Deserialize(std::shared_ptr<Deserializer> p_deserializer)
{
	if (!p_deserializer->Deserialize(health))
		return false;
	if (!p_deserializer->Deserialize(life))
		return false;
	return true;
}
