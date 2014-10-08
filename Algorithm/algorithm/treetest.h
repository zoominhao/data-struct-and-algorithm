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
	vector<vector<int>>  zigZagLevelOrder(TreeNode* root);
	// Given a binary tree, determine if it is a valid binary search tree (BST). 
	// Assume a BST is defined as follows: The left subtree of a node contains only nodes with keys less than the node's key. 
	// The right subtree of a node contains only nodes with keys greater than the node's key. 
	// Both the left and right subtrees must also be binary search trees. 
	bool isValidBST(TreeNode* root);

	bool isBalancedTree(TreeNode* root);
	bool isBalanced(TreeNode* root, int& depth);

	int minDepth(TreeNode* root);
	int maxDepth(TreeNode* root);

	bool isSameTree(TreeNode* root1, TreeNode* root2);
	bool isSymmetricTree( TreeNode* root );

	void destroyTree(TreeNode* root);

	bool deleteBST(TreeNode* root, int target );
	bool deleteNode(TreeNode* node);

	bool insertBST(TreeNode* root, TreeNode* node);
	TreeNode* searchBST(TreeNode* root, int target); 
	void insertBST2(TreeNode* root, TreeNode* node);
	bool searchBST2(TreeNode* root, int target );

	void testValid( void );

	//BFS and DFS of the tree
	vector<int> DFS(TreeNode* root);
	vector<int> BFS(TreeNode* root);


	//isSubtree
	bool isSubTree(TreeNode* T1, TreeNode* T2);

	//build tree from inOrder and postOrder
	TreeNode* buildTreeFromInandPost(vector<int>& inOrder, vector<int>& postOrder);
	TreeNode* buildIPHelper(vector<int>::iterator inL, vector<int>::iterator inR, 
		vector<int>::iterator postL, vector<int>::iterator postR);
	//build tree from preOrder and inOrder
	TreeNode* buildTreeFromPreandIn(vector<int>& preOrder, vector<int>& inOrder);
	TreeNode* buildPIHelper(vector<int>::iterator preL, vector<int>::iterator preR, 
		vector<int>::iterator inL, vector<int>::iterator inR);

	//print BST keys in the given range
	//Given two values k1 and k2 (where k1 < k2) and a root pointer to a Binary Search Tree. 
	//Print all the keys of tree in range k1 to k2. i.e. print all x such that k1<=x<=k2 and 
	//x is a key of given BST. Print all the keys in increasing order.
	vector<int> rangeSearchOnBST(TreeNode* root, int k1, int k2);

	void testSearch(void);

	//lowest common ancestor
	TreeNode* lcaBST(TreeNode* root, TreeNode* node1, TreeNode* node2);
	TreeNode* lca(TreeNode* root, TreeNode* node1, TreeNode* node2);
	bool isCover(TreeNode* root, TreeNode* node);

};

