#pragma once
#include <string>
enum SaveandLoad_Result
{
	SUCCESS,
	FAILED_COULD_NOT_SERIALIZE_YOUR_DATA,
	FAILED_COULD_NOT_CREATE_FILE_IN_DIRECTORY,
	FAILED_COULD_NOT_OPEN_FILE_IN_DIRECTORY,
	FAILED_FILE_IS_EMPTY,
	FAILED_COULD_NOT_DESERIALIZE_YOUR_DATA,
};

class ISerializable;
class GameSaver
{
public:
	GameSaver() = delete;
	GameSaver(std::string p_path);
	~GameSaver();

	SaveandLoad_Result Save( ISerializable& p_serializable);
	SaveandLoad_Result Load (ISerializable& p_serializable);
private:
	std::string m_path;
};

