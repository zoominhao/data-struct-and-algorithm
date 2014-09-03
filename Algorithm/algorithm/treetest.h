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
     TreeNode(int x, TreeNode* nleft = NULL, TreeNode* nright = NULL)
		 :val(x), left(nleft), right(nright)
	 {

	 }
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

	//  Given a binary tree, return the level order traversal of its nodes' values.
	// (ie, from left to right, level by level). For example: Given binary tree {3,9,20,#,#,15,7},
	// 3 / \ 9 20 / \ 15 7 return its level order traversal as: [ [3], [9,20], [15,7] ]
	vector<vector<int>> levelOrder( TreeNode* root );

	// Given a binary tree, determine if it is a valid binary search tree (BST). 
	// Assume a BST is defined as follows: The left subtree of a node contains only nodes with keys less than the node's key. 
	// The right subtree of a node contains only nodes with keys greater than the node's key. 
	// Both the left and right subtrees must also be binary search trees. 
	bool isValidBST(TreeNode* root);

	bool isBalancedTree(TreeNode* root);
		
};