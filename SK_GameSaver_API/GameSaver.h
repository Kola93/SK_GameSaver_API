#pragma once
#include <string>
class ISerializable;
class GameSaver
{
public:
	GameSaver(std::string p_path);
	~GameSaver();


	void Save( ISerializable& p_serializable);
	void Load (ISerializable& p_serializable);
private:
	std::string m_path;
};

