#pragma once

#include <iostream>
#include <queue>
#include <stack>
#include <cassert>
using namespace std;

const bool RED = true;
const bool BLACK = false;

struct TreeNode{
	int val;
	TreeNode *left, *right;
	bool color;    //red: 1, black: 0
	int N;
	TreeNode(int x, bool c, int s) : val(x), left(NULL), right(NULL), color(c), N(s){}
};

class RedBlackTree
{
public:
	RedBlackTree(int n);
	bool isRed(TreeNode *root);
	int size(TreeNode *root);
	void insert(TreeNode *&root, int val);
	bool search(TreeNode *root, int target);
	TreeNode* selectRank(TreeNode *root, int k);
	int getRank(TreeNode *root, int target);
private:
	TreeNode* rotateLeft(TreeNode *root);
	TreeNode* rotateRight(TreeNode *root);
	void flipColors(TreeNode *root);

private:
	TreeNode *root;
};