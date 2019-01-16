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

	GameSaver GS("./SaveFolder/testUserStruct.txt");
	GS.SetGenerateLogFileActive();
	bool SaveResult = GS.Save(xUserStructSave);
	EXPECT_EQ(SaveResult, true);

	UserStruct xUserStructLoad;
	bool LoadResult = GS.Load(&xUserStructLoad);
	EXPECT_EQ(LoadResult, true);

	EXPECT_EQ(xUserStructSave.int_value, xUserStructLoad.int_value);
	EXPECT_EQ(xUserStructSave.float_value, xUserStructLoad.float_value);
	EXPECT_EQ(xUserStructSave.bool_value, xUserStructLoad.bool_value);
	EXPECT_EQ(xUserStructSave.char_value, xUserStructLoad.char_value);
	EXPECT_EQ(xUserStructSave.string_value, xUserStructLoad.string_value);
	EXPECT_EQ(xUserStructSave.double_value, xUserStructLoad.double_value);
}

TEST(AUserClass, CanSaveAndLoadDataWithAnyCustomFileExtension) {

	UserStruct xUserStructSave;
	xUserStructSave.int_value = 5;
	xUserStructSave.float_value = 8.99f;
	xUserStructSave.bool_value = true;
	xUserStructSave.char_value = 'd';
	xUserStructSave.string_value = "Save";

	GameSaver GS("./SaveFolder/testUserStruct.myfile");
	GS.SetGenerateLogFileActive();
	bool SaveResult = GS.Save(xUserStructSave);
	EXPECT_EQ(SaveResult, true);

	UserStruct xUserStructLoad;
	bool LoadResult = GS.Load(&xUserStructLoad);
	EXPECT_EQ(LoadResult, true);

	EXPECT_EQ(xUserStructSave.int_value, xUserStructLoad.int_value);
	EXPECT_EQ(xUserStructSave.float_value, xUserStructLoad.float_value);
	EXPECT_EQ(xUserStructSave.bool_value, xUserStructLoad.bool_value);
	EXPECT_EQ(xUserStructSave.char_value, xUserStructLoad.char_value);
	EXPECT_EQ(xUserStructSave.string_value, xUserStructLoad.string_value);
	EXPECT_EQ(xUserStructSave.double_value, xUserStructLoad.double_value);
}

TEST(TheUser, GetErrorWhenLoadingANotExistingFile) {
	GameSaver GS("./SaveFolder/xxx.txt");
	UserStruct xUserStructLoad;
	ASSERT_ANY_THROW(GS.Load(&xUserStructLoad));
}

TEST(TheUser, GetErrorWhenLoadingAFileWithNoData) {
	GameSaver GS("./SaveFolder/EmptyFile.txt");
	UserStruct xUserStructLoad;
	ASSERT_ANY_THROW(GS.Load(&xUserStructLoad));
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
	GameSaver GS("../user/wrongdirectory/text.txt");
	UserStruct2 xUserStruct2Save;
	ASSERT_ANY_THROW(GS.Save(xUserStruct2Save));
}

TEST(TheUser, GetErrorWhenTryingToDeserializeDataOutOfRange) {
	struct UserStruct2 : public ISerializable
	{
		int int_value = 8;
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
	GameSaver GS("./SaveFolder/TestUserStruct2.txt");
	UserStruct2 xUserStruct2Save;

	bool SaveResult = GS.Save(xUserStruct2Save);
	EXPECT_EQ(SaveResult, true);
	ASSERT_ANY_THROW(GS.Load(&xUserStruct2Save));
}

