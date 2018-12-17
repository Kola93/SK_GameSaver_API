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
	delete[] m_data;
	m_data = nullptr;
}

void ByteStream::DeleteEmptySpace()
{
	Reserve(m_length);
}

char * ByteStream::GetBuffer()
{
	return m_data;
}

int ByteStream::GetSize()
{
	return m_length;
}

std::vector<std::string> ByteStream::GetSaveHistory()
{
	return m_debugBuffer;
}

bool ByteStream::Write(int p_count, std::string p_value)
{
	assert(p_count == static_cast<int>(p_value.size()) && "Error: Number of chars is different from size of string");
	
	if (m_length == 0 || m_capacity == m_length)
	{
		Reserve(m_capacity + static_cast<int>(p_value.size()));
	}

	m_cursor = m_data + m_length;
	for (int i = 0; i < p_count; ++i)
	{
		try
		{
			*reinterpret_cast<char *>(m_cursor) = p_value[i];
			m_cursor++;
		}
		catch (std::exception& e)
		{
			std::cout << "Exception: " << e.what() << std::endl;
			return false;
		}
	}
	m_debugBuffer.push_back(p_value);
	m_length += p_count;
	return true;
}

bool ByteStream::Read(int p_count, std::string& p_value)
{
	for (int i = 0; i < p_count; ++i)
	{
		try
		{
			p_value += *reinterpret_cast<char *>(m_cursor);
			m_cursor++;
		}
		catch (std::exception& e)
		{
			std::cout << "Exception: " << e.what() << std::endl;
			return false;
		}	
	}
	return true;
}

void ByteStream::Reserve(const int& p_NewAmount)
{
	char* xNewData = new char[p_NewAmount];

	std::copy(m_data, m_data + m_length, xNewData);
	delete[] m_data;
	m_data = nullptr;

	m_data = xNewData;

	m_capacity = p_NewAmount;
}

bool ByteStream::IsOutsideEndStreamBoundary()
{
	int length = static_cast<int>(m_cursor - m_data);
	if(length + 1 > m_length)
	{
		return true;
	}
	return false;
}

void ByteStream::ResetCursor() 
{
	m_cursor = m_data;
}


