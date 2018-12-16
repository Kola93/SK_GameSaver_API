#pragma once
#include <cassert>
#include <exception>
#include <iostream>
#include <string>

class ByteStream
{
public:
	ByteStream();
	ByteStream(int p_size);
	~ByteStream();

	void DeleteEmptySpace();

	char* GetBuffer();	
	int GetSize();
	void ResetCursor();

	bool Write(int p_count, std::string p_value);
	bool Read(int p_count, std::string& p_value);

	template<typename T>
	bool Write(T p_value);

	template<typename T>
	bool Read(T& p_value);
private:	
	int m_capacity;
	int m_length;
	char* m_data;
	char* m_cursor;

	void Reserve(const int& p_NewAmount);
	bool IsOutsideEndStreamBoundary();
};


template <typename T>
bool ByteStream::Write(T p_value)
{	
	if (m_length == 0 || m_capacity == m_length)
	{
		Reserve(m_capacity + sizeof(T) * 2);
	}
	m_cursor = m_data + m_length;
	try
	{
		 *reinterpret_cast<T *>(m_cursor) = p_value;
	}
	catch(std::exception& e)
	{
		std::cout << "Exception: " << e.what() << std::endl;		
		return false;
	}
	m_length += sizeof(T);
	return true;
}


template<typename T>
bool ByteStream::Read(T& p_value)
{
	if(!IsOutsideEndStreamBoundary())
	{	
		try
		{
			p_value = *reinterpret_cast<T *>(m_cursor);
		}
		catch (std::exception& e)
		{
			std::cout << "Exception: " << e.what() << std::endl;
			return false;
		}
		m_cursor += sizeof(T);
		return true;
	}
	return false;
}
 