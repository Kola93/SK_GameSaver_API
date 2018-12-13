#include "ByteStream.h"
#include <algorithm>


ByteStream::ByteStream()
{
	m_data = nullptr;
	m_length = 0;
	m_capacity = 0;
	m_cursor = nullptr;
}

ByteStream::ByteStream(int p_size)
{
	m_data = new char[p_size];
	m_length = p_size;
	m_capacity = p_size;
	m_cursor = m_data;
}


ByteStream::~ByteStream()
{
}

char * ByteStream::GetBuffer()
{
	return m_data;
}

int ByteStream::GetSize()
{
	return m_length;
}

void ByteStream::reserve(const int& newAmount)
{
	char* xNewData = new char[newAmount];

	std::copy(m_data, m_data + m_length, xNewData);
	delete[] m_data;
	m_data = nullptr;

	m_data = xNewData;
	//m_cursor = m_data + m_length;
	m_capacity = newAmount;
	
}
