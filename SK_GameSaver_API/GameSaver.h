#pragma once
#include <string>
enum SaveandLoad_Result
{
	SUCCESS,
	FAILED_COULD_NOT_SERIALIZE_YOUR_DATA,
	FAILED_COULD_NOT_CREATE_FILE_IN_DIRECTORY,
	FAILED_COULD_NOT_CREATE_LOG_FILE_IN_DIRECTORY,
	FAILED_COULD_NOT_OPEN_FILE_IN_DIRECTORY,
	FAILED_FILE_IS_EMPTY,
	FAILED_COULD_NOT_DESERIALIZE_YOUR_DATA,
};

class ISerializable;
class ByteStream;
class GameSaver
{
public:
	GameSaver() = delete;
	GameSaver(std::string p_FilePath, std::string p_FileName, std::string p_extension);
	~GameSaver() = default;

	SaveandLoad_Result Save (ISerializable& p_serializable);
	SaveandLoad_Result Load (ISerializable* p_serializable);

	void SetGenerateLogFileActive();
	
private:
	std::string m_FIlePath;
	std::string m_FIleName;
	std::string m_FIleExtension;
	bool m_generateLogFile;
	SaveandLoad_Result GenerateFileLog(const std::shared_ptr<ByteStream> xByteStream_ptr);
};

