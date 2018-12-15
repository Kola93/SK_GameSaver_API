#include "pch.h"
#include "UserStruct.h"
#include "../SK_GameSaver_API/Serializer.h"
#include "../SK_GameSaver_API/Deserializer.h"
UserStruct::UserStruct()
{
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
	if (!p_serializer->Serialize(char_value))
		return false;
	if (!p_serializer->Serialize(4, string_value))
		return false;
	if (!p_serializer->Serialize(double_value))
		return false;
	/*for (int i = 0; i < string_value.size(); ++i)
	{
		if (!p_serializer->Serialize(string_value[i]))
			return false;
	}
	*/
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
	if (!p_deserializer->Deserialize(char_value))
		return false;
	if (!p_deserializer->Deserialize(4,string_value))
		return false;
	if (!p_deserializer->Deserialize(double_value))
		return false;
	/*for (int i = 0; i < string_value.size(); ++i)
	{
		if (!p_deserializer->Deserialize(string_value[i]))
			return false;
	}*/
	return true;
}

