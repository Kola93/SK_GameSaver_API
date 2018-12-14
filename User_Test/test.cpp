#include "pch.h"
#include "../SK_GameSaver_API/ISerializable.h"
#include "../SK_GameSaver_API/GameSaver.h"


TEST(ISS, SSS) {
	class UserStruct : public ISerializable
	{
	public:
		int int_value;
		float float_value;
		bool bool_value;
		UserStruct() {};
		~UserStruct() {};
		bool Serialize(std::shared_ptr<Serializer> p_serializer) override
		{
			if (!p_serializer->Serialize(int_value))
				return false;
			/*	if (!p_serializer->Serialize(float_value))
					return false;
				if (!p_serializer->Serialize(bool_value))
					return false;*/
			return true;
		}
		bool Deserialize(std::shared_ptr<Deserializer> p_deserializer) override
		{
			if (!p_deserializer->Deserialize(int_value))
				return false;
			/*	if (!p_deserializer->Deserialize(float_value))
					return false;
				if (!p_deserializer->Deserialize(bool_value))
					return false;*/
			return true;
		}

	};
	UserStruct xUserStructSave;
	xUserStructSave.int_value = 5;
	//xUserStructSave.life = 85;

	GameSaver GS("testUserStruct.txt");
	GS.Save(xUserStructSave);

	UserStruct xUserStructLoad;
	GS.Load(xUserStructLoad);

	EXPECT_EQ(xUserStructSave.int_value, xUserStructLoad.int_value);
}