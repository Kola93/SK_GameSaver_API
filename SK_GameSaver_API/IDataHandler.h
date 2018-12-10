#pragma once
class IDataHandler
{
public:
	IDataHandler();
	virtual ~IDataHandler();

	virtual bool Serialize(const int& value) = 0;
};

