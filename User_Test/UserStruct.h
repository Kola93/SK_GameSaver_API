#pragma once
#include "../SK_GameSaver_API/IDataHandler.h"
#include "../SK_GameSaver_API/ISerializable.h"

class UserStruct : public ISerializable
{
public:
	int int_value = 0;
	float float_value = 0.f;
	bool bool_value = false;
	UserStruct();
	~UserStruct();
	bool Serialize(std::shared_ptr<Serializer> p_serializer) override;
	bool Deserialize(std::shared_ptr<Deserializer> p_deserializer) override;

};
