#pragma once
#include <cassert>

class ByteStream
{
public:
	ByteStream();
	ByteStream(int p_size);
	~ByteStream();
	char* GetBuffer();
	int GetSize();

	template<typename T>
	bool Write(T p_value);
	template<typename T>
	bool Read(T& p_value);
private:

	int m_capacity;
	int m_length;
	char* m_data;

	int* m_at;
	char* m_cursor;


	void reserve(const int& p_NewAmount);
};


template <typename T>
bool ByteStream::Write(T p_value)
{
	//assert(sizeof(p_value) <= sizeof(int) && "You are using a type larger then 4 bytes");
	if (m_length == 0 || m_capacity == m_length)
	{
		reserve(m_capacity + sizeof(T));
	}
	m_cursor = m_data + m_length;
	*reinterpret_cast<T *>(m_cursor) = p_value;
	//m_cursor += sizeof(T);
	m_length += sizeof(T);
	return true;
}


template<typename T>
bool ByteStream::Read(T& p_value)
{
	p_value = *reinterpret_cast<T *>(m_cursor);
	m_cursor += sizeof(T);
	return true;
}
