#include "pch.h"
#include "UserStruct.h"
// note: unity build
#include "../SK_GameSaver_API/ByteStream.cpp"
#include "../SK_GameSaver_API/Deserializer.cpp"
#include "../SK_GameSaver_API/GameSaver.cpp"
#include "../SK_GameSaver_API/ISerializable.cpp"
#include "../SK_GameSaver_API/Serializer.cpp"


TEST(AUserClass, CanSaveAndLoadDataOfAnyType) {

	UserStruct xUserStructSave;
	xUserStructSave.int_value = 5;
	xUserStructSave.float_value = 8.99f;
	xUserStructSave.bool_value = true;
	xUserStructSave.char_value = 'd';
	xUserStructSave.string_value = "Save";
	xUserStructSave.double_value = 0.58584848114495952;

	GameSaver GS("testUserStruct.txt");
	GS.Save(xUserStructSave);

	UserStruct xUserStructLoad;
	GS.Load(xUserStructLoad);

	EXPECT_EQ(xUserStructSave.int_value, xUserStructLoad.int_value);
	EXPECT_EQ(xUserStructSave.float_value, xUserStructLoad.float_value);
	EXPECT_EQ(xUserStructSave.bool_value, xUserStructLoad.bool_value);
	EXPECT_EQ(xUserStructSave.char_value, xUserStructLoad.char_value);
	EXPECT_EQ(xUserStructSave.string_value, xUserStructLoad.string_value);
	EXPECT_EQ(xUserStructSave.double_value, xUserStructLoad.double_value);
}

TEST(AUserClass, CanSaveAndLoadDataWithBinExtention) {

	UserStruct xUserStructSave;
	xUserStructSave.int_value = 5;
	xUserStructSave.float_value = 8.99f;
	xUserStructSave.bool_value = true;
	xUserStructSave.char_value = 'd';
	xUserStructSave.string_value = "Save";

	GameSaver GS("testUserStruct.bin");
	GS.Save(xUserStructSave);

	UserStruct xUserStructLoad;
	GS.Load(xUserStructLoad);

	EXPECT_EQ(xUserStructSave.int_value, xUserStructLoad.int_value);
	EXPECT_EQ(xUserStructSave.float_value, xUserStructLoad.float_value);
	EXPECT_EQ(xUserStructSave.bool_value, xUserStructLoad.bool_value);
	EXPECT_EQ(xUserStructSave.char_value, xUserStructLoad.char_value);
	EXPECT_EQ(xUserStructSave.string_value, xUserStructLoad.string_value);
	EXPECT_EQ(xUserStructSave.double_value, xUserStructLoad.double_value);
}

TEST(AUserClass, CanSaveAndLoadDataWithAnyCustomExtention) {

	UserStruct xUserStructSave;
	xUserStructSave.int_value = 5;
	xUserStructSave.float_value = 8.99f;
	xUserStructSave.bool_value = true;
	xUserStructSave.char_value = 'd';
	xUserStructSave.string_value = "Save";

	GameSaver GS("testUserStruct.myfile");
	GS.Save(xUserStructSave);

	UserStruct xUserStructLoad;
	GS.Load(xUserStructLoad);

	EXPECT_EQ(xUserStructSave.int_value, xUserStructLoad.int_value);
	EXPECT_EQ(xUserStructSave.float_value, xUserStructLoad.float_value);
	EXPECT_EQ(xUserStructSave.bool_value, xUserStructLoad.bool_value);
	EXPECT_EQ(xUserStructSave.char_value, xUserStructLoad.char_value);
	EXPECT_EQ(xUserStructSave.string_value, xUserStructLoad.string_value);
	EXPECT_EQ(xUserStructSave.double_value, xUserStructLoad.double_value);
}

TEST(TheUser, GetErrorWhenLoadingANotExistingFile) {
	GameSaver GS("xxx.txt");

	UserStruct xUserStructLoad;
	SaveandLoad_Result result = GS.Load(xUserStructLoad);
	EXPECT_EQ(result, SaveandLoad_Result::FAILED_COULD_NOT_OPEN_FILE_IN_DIRECTORY);
}

TEST(TheUser, GetErrorWhenCreatingFileWithWrongDirectory) {
	struct UserStruct2 : public ISerializable
	{
		int int_value = 0;
		bool Serialize(std::shared_ptr<Serializer> p_serializer) override
		{
			if (!p_serializer->Serialize(int_value))
				return false;
			return true;
		}
		bool Deserialize(std::shared_ptr<Deserializer> p_deserializer) override
		{
			if (!p_deserializer->Deserialize(int_value))
				return false;
			return true;
		}
	};
	GameSaver GS("/user/wrongdirectory/text.txt");
	UserStruct2 xUserStruct2Save;

	SaveandLoad_Result Saveresult = GS.Save(xUserStruct2Save);

	EXPECT_EQ(Saveresult, SaveandLoad_Result::FAILED_COULD_NOT_CREATE_FILE_IN_DIRECTORY);
}

TEST(TheUser, GetErrorWhenTryingToDeserializeDataNotAvailable) {
	struct UserStruct2 : public ISerializable
	{
		int int_value = 0;
		bool Serialize(std::shared_ptr<Serializer> p_serializer) override
		{
			if (!p_serializer->Serialize(int_value))
				return false;
			return true;
		}
		bool Deserialize(std::shared_ptr<Deserializer> p_deserializer) override
		{
			if (!p_deserializer->Deserialize(int_value))
				return false;
			if (!p_deserializer->Deserialize(int_value))
				return false;
			return true;
		}
	};
	GameSaver GS("TestUserStruct2.txt");
	UserStruct2 xUserStruct2Save;

	SaveandLoad_Result Saveresult = GS.Save(xUserStruct2Save);
	SaveandLoad_Result Loadresult = GS.Load(xUserStruct2Save);

	EXPECT_EQ(Loadresult, SaveandLoad_Result::FAILED_COULD_NOT_DESERIALIZE_YOUR_DATA);
}