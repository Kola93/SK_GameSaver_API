#pragma once
#include <cassert>
#include <exception>
#include <iostream>
#include <string>
#include <vector>
class ByteStream
{
public:
	ByteStream();
	ByteStream(int p_size);
	~ByteStream();

	void DeleteEmptySpace();

	char* GetBuffer();	
	size_t GetSize();
	void ResetCursor();

	std::vector<std::string> GetSaveHistory();
	bool Write(int p_count, std::string p_value);
	bool Read(int p_count, std::string& p_value);

	template<typename T>
	bool Write(T p_value);

	template<typename T>
	bool Read(T& p_value);
private:	
	size_t m_capacity;
	size_t m_length;
	char* m_data;
	char* m_cursor;
	std::vector<std::string> m_debugBuffer;

	void Reserve(const size_t& p_NewAmount);
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
	catch (const char* error){
		const std::string xError = "Counldn't serialize your data of type: " + std::string(typeid(T).name()) + " and value: " + std::to_string(p_value) + " - Error: " + std::string(error);
		throw std::exception(xError.c_str());
	}	
	m_length += sizeof(T);
	m_debugBuffer.push_back(std::to_string(p_value));
	return true;
}


template<typename T>
bool ByteStream::Read(T& p_value)
{
	if(!IsOutsideEndStreamBoundary())
	{	
		try
		{
			p_value = *(reinterpret_cast<T *>(m_cursor));
		}
		catch (const char* error) {
			const std::string xError = "Counldn't deserialize your data of type: " + std::string(typeid(T).name()) + " - Error: " + std::string(error);
			throw std::exception(xError.c_str());
		}		
		m_cursor += sizeof(T);
		return true;
	}
	const std::string xError = "Counldn't deserialize your data of type: " + std::string(typeid(T).name()) + " - Cursor out of range! You are deserializing more data than available!";
	throw std::exception(xError.c_str());

}
 