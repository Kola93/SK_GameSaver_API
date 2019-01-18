#pragma once
#include <string>

class ISerializable;
class ByteStream;
class GameSaver
{
public:
	GameSaver() = delete;
	GameSaver(std::string p_FileDirectory, std::string p_FileName, std::string p_extension);
	GameSaver(std::string p_FilePath);
	~GameSaver() = default;

	bool Save (ISerializable& p_serializable);
	bool Load (ISerializable* p_serializable);

	void SetGenerateLogFileActive();
	
private:
	std::string m_FIlePath;
	std::string m_FIleName;
	std::string m_FIleExtension;
	std::string m_FullFilePath;
	bool m_generateLogFile;
	bool GenerateFileLog(const std::shared_ptr<ByteStream> xByteStream_ptr);
};

