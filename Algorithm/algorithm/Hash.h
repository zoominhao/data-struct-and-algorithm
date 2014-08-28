#pragma once

#include <iostream>

using namespace std;

class HashTable
{
public:
	HashTable(int length);
	~HashTable();

	int Hash(int key);
	int Hash2(int key);
	//linear way to resolve conflict
	void linearInsert(int key);
	bool linearSearch(int key, int* addr);
	//random way to resolve conflict
	void randInsert(int key);
	bool randSearch(int key, int* addr);

private:
	int *m_elems;
	int m_length;
	int m_sum;
};