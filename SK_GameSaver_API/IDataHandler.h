#pragma once
class IDataHandler
{
public:
	IDataHandler();
	virtual ~IDataHandler();

	virtual bool Serialize(int value) = 0;
};

