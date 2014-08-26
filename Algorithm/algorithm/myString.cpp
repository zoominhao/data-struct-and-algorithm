#include "myString.h"

MyString::~MyString()
{
	delete[] m_data;
	//delete m_data;  //both are ok
}

MyString::MyString(const MyString &other)
{
	int length = strlen(other.m_data);
	m_data = new char[length];
	strcpy(m_data, other.m_data);
}

MyString::MyString(const char* str /*= NULL*/)
{
	if (str == NULL)
	{
		m_data = new char[1];
		*m_data = '\0';
	}
	else
	{
		int length = strlen(str);
		//m_data = (char*)malloc((length + 1) * sizeof(char));
		m_data = new char[length];
		strcpy(m_data, str);
	}
}

MyString &MyString::operator=(const MyString &other)
{
	if (this == &other)
	   return *this;
	
	delete[] m_data;

	int length = strlen(other.m_data);
	m_data = new char[length];
	strcpy(m_data, other.m_data);
    
	return *this;
}