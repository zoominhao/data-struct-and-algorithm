#include "Hash.h"

HashTable::HashTable( int length )
{
	m_length = length;
	m_elems = new int[length];
	for (int i = 0; i < m_length; i++)
	{
		m_elems[i] = INT_MIN;
	}
	m_sum = 0;
}

HashTable::~HashTable()
{
	delete m_elems;
}

int HashTable::Hash( int key )
{
	return key % m_length;
}

int HashTable::Hash2(int key)
{
	m_sum = m_sum * 33 + key;
	m_sum = m_sum % m_length;
	return m_sum;
}

void HashTable::linearInsert( int key )
{
	int addr = Hash(key);
	while (m_elems[addr] != INT_MIN)
	{
		addr = (addr + 1) % m_length;
	}
	m_elems[addr] = key;
}

bool HashTable::linearSearch( int key, int* addr )
{
	*addr = Hash(key);
	while (m_elems[*addr] != key)
	{
		*addr = (*addr + 1) % m_length;
		if(*addr == Hash(key) || m_elems[*addr] == INT_MIN)
		{
			return false;
		}
	}
	return true;
}

void HashTable::randInsert( int key )
{
	int addr = Hash(key);
	while (m_elems[addr] != INT_MIN)
	{
		addr = (addr + rand()) % m_length;
	}
	m_elems[addr] = key;
}

bool HashTable::randSearch( int key, int* addr )
{
	*addr = Hash(key);
	while (m_elems[*addr] != key)
	{
		*addr = (*addr + rand()) % m_length;
		if (*addr == Hash(key) || m_elems[*addr] == INT_MIN)
		{
			return false;
		}
	}
	return true;
}

