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



