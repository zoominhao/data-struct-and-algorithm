#pragma 

#include<iostream>

using namespace std;

struct ListNode
{ 
	int val;
	ListNode* next;
	ListNode(int nval = 0, ListNode* nnext = NULL):val(nval), next(nnext) {} 
};

class LinkedHashTable
{
public:
	LinkedHashTable(int length = 0);
	~LinkedHashTable();

	int Hash(int key);

	void insertHashTable(int key);
	bool searchHashTable(int key, int* addr);

private:
	ListNode*(*m_elems);

	int m_length;
};