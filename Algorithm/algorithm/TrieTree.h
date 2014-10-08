#pragma once

#include <iostream>
using namespace std;

const int MAX = 26;

struct TrieNode
{
	bool isStr;                   //标记该结点处是否构成单词 
	TrieNode* next[MAX];   //儿子分支
};

class TrieTree
{
public:
	void insert(TrieNode* root, const char* s);
	int search(TrieNode* root, const char* s);

	void del(TrieNode* root);

	void test(void);
};