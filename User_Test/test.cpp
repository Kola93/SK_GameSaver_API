#include "pch.h"
#include "UserStruct.h"
// note: unity build
#include "../SK_GameSaver_API/ByteStream.cpp"
#include "../SK_GameSaver_API/Deserializer.cpp"
#include "../SK_GameSaver_API/GameSaver.cpp"
#include "../SK_GameSaver_API/IDataHandler.cpp"
#include "../SK_GameSaver_API/ISerializable.cpp"
#include "../SK_GameSaver_API/Serializer.cpp"


TEST(AUserClass, CanSaveAndLoadData) {

	UserStruct xUserStructSave;
	xUserStructSave.int_value = 5;
	xUserStructSave.float_value = 8.99f;
	xUserStructSave.bool_value = true;

	GameSaver GS("testUserStruct.txt");
	GS.Save(xUserStructSave);

	UserStruct xUserStructLoad;
	GS.Load(xUserStructLoad);

	EXPECT_EQ(xUserStructSave.int_value, xUserStructLoad.int_value);
	EXPECT_EQ(xUserStructSave.float_value, xUserStructLoad.float_value);
	EXPECT_EQ(xUserStructSave.bool_value, xUserStructLoad.bool_value);
}

