#include "pch.h"
#include "UserStruct.h"
#include "../SK_GameSaver_API/Serializer.h"
#include "../SK_GameSaver_API/Deserializer.h"
UserStruct::UserStruct()
{
	int_value = 0;
	float_value = 0;
	bool_value = 0;
}

UserStruct::~UserStruct()
{
}

bool UserStruct::Serialize(std::shared_ptr<Serializer> p_serializer)
{
	if (!p_serializer->Serialize(int_value))
		return false;
		if (!p_serializer->Serialize(float_value))
			return false;
		if (!p_serializer->Serialize(bool_value))
			return false;
	return true;
}

bool UserStruct::Deserialize(std::shared_ptr<Deserializer> p_deserializer)
{
	if (!p_deserializer->Deserialize(int_value))
		return false;
		if (!p_deserializer->Deserialize(float_value))
			return false;
		if (!p_deserializer->Deserialize(bool_value))
			return false;
	return true;
}

