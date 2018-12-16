#include "pch.h"
// note: unity build
#include "../SK_GameSaver_API/ByteStream.cpp"
#include "../SK_GameSaver_API/Deserializer.cpp"
#include "../SK_GameSaver_API/GameSaver.cpp"
#include "../SK_GameSaver_API/ISerializable.cpp"
#include "../SK_GameSaver_API/Serializer.cpp"


TEST(AByteStream, IsDefaultConstructible) {
	ByteStream BS;
	int size = 2;
	ByteStream BS2(size);
	EXPECT_EQ(BS.GetSize(), 0);
	EXPECT_EQ(BS2.GetSize(), 2);
}

TEST(AByteStream, IsConstructibleWithSize) {
	int size = 2;
	ByteStream BS(size);
	EXPECT_EQ(BS.GetSize(), size);
}

TEST(AByteStream, CanWriteandReadInt) {
	ByteStream BS;
	int Write_value = 2;
	int Read_value = 0;
	EXPECT_TRUE(BS.Write(Write_value));
	BS.DeleteEmptySpace();
	BS.ResetCursor();
	EXPECT_TRUE(BS.Read(Read_value));
	EXPECT_EQ(Write_value, Read_value);
}

TEST(AByteStream, CanWriteandReadFloat) {
	ByteStream BS;
	float Write_value = 2.5f;
	float Read_value = 0.f;
	EXPECT_TRUE(BS.Write(Write_value));
	BS.DeleteEmptySpace();
	BS.ResetCursor();
	EXPECT_TRUE(BS.Read(Read_value));
	EXPECT_EQ(Write_value, Read_value);
}

TEST(AByteStream, CanWriteandReadBool) {
	ByteStream BS;
	bool Write_value = true;
	bool Read_value = false;
	EXPECT_TRUE(BS.Write(Write_value));
	BS.DeleteEmptySpace();
	BS.ResetCursor();
	EXPECT_TRUE(BS.Read(Read_value));
	EXPECT_EQ(Write_value, Read_value);
}

TEST(AByteStream, CanWriteandReadChar) {
	ByteStream BS;
	char Write_value = 'A';
	char Read_value = ' ';
	EXPECT_TRUE(BS.Write(Write_value));
	BS.DeleteEmptySpace();
	BS.ResetCursor();
	EXPECT_TRUE(BS.Read(Read_value));
	EXPECT_EQ(Write_value, Read_value);
}

TEST(AByteStream, CanWriteandReadString) {
	ByteStream BS;
	std::string Write_value = "TestingWriteAndReadString";
	std::string Read_value = "";
	EXPECT_TRUE(BS.Write(static_cast<int>(Write_value.size()), Write_value));
	BS.DeleteEmptySpace();
	BS.ResetCursor();
	EXPECT_TRUE(BS.Read(static_cast<int>(Write_value.size()), Read_value));
	EXPECT_EQ(Write_value, Read_value);
}


