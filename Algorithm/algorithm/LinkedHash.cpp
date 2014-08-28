#include "LinkedHash.h"

LinkedHashTable::LinkedHashTable( int length /*= 0*/ )
{
	m_length = length;
	m_elems = new ListNode*[length];
	for (int i = 0; i < m_length; ++i)
	{
		m_elems[i] = new ListNode();
	}
}

LinkedHashTable::~LinkedHashTable()
{
	delete[] m_elems;
}

int LinkedHashTable::Hash( int key )
{
	return key % m_length;
}

void LinkedHashTable::insertHashTable( int key )
{
	int addr = Hash(key);
	ListNode *t = new ListNode(key);
	t->next = m_elems[addr]->next;
	m_elems[addr]->next = t;
}

bool LinkedHashTable::searchHashTable( int key, int* addr )
{
	*addr = Hash(key);
	ListNode* dummy = m_elems[*addr];
	ListNode* p = dummy->next;
	while (p != NULL)
	{
		if (p->val == key )
		{
			return true;
		}
		p = p->next;
	}
	return false;
}
