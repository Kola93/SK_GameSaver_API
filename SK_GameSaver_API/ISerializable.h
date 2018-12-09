#pragma once
class ISerializable
{
public:
	ISerializable();
	virtual ~ISerializable();

	virtual bool Serialize() = 0;
	virtual bool DeSerialize() = 0;
};

