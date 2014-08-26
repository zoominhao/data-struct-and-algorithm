#pragma once
#include <iostream>
#include <stack>
#include <queue>

using namespace std;


//Definition for binary tree
struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x, TreeNode* nleft = NULL, TreeNode* nright = NULL): val(x), left(nleft), right(nright){}
};
 

class TreeTest
{
public:
	// Given a binary tree, return the preorder traversal of its nodes' values. 
	// For example: Given binary tree {1,#,2,3}, 1 \ 2 / 3 return [1,2,3]. Note: Recursive solution is trivial, could you do it iteratively?
	vector<int> preorderTraversal(TreeNode* root);
	vector<int> preorderTraversal2(TreeNode* root);    //divide & conquer
	vector<int> preorderTraversal3(TreeNode* root);    //recursion
	void preorderTraversalHelper(TreeNode* root, vector<int>& preorder);

	// Given a binary tree, return the postorder traversal of its nodes' values. 
	// For example: Given binary tree {1,#,2,3}, 1 \ 2 / 3 return [3,2,1]. 
    // Note: Recursive solution is trivial, could you do it iteratively? 
	vector<int> postorderTraversal(TreeNode* root);
	vector<int> postorderTraversal2(TreeNode* root);

	vector<int> inorderTraversal(TreeNode* root);
	vector<int> inorderTraversal2(TreeNode* root);

	void testTraversal( void );
		
};