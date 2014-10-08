#pragma once

#include <iostream>
using namespace std;

const int MAX = 26;

struct TrieNode
{
	bool isStr;                   //��Ǹý�㴦�Ƿ񹹳ɵ��� 
	TrieNode* next[MAX];   //���ӷ�֧
};

class TrieTree
{
public:
	void insert(TrieNode* root, const char* s);
	int search(TrieNode* root, const char* s);

	void del(TrieNode* root);

	void test(void);
};