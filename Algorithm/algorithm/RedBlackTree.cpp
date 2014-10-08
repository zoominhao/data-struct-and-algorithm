#include "RedBlackTree.h"
RedBlackTree::RedBlackTree( int n )
{
	root = NULL;
	for(int i = 0; i < n; ++i){
		insert(root, i);
		root->color = BLACK;//every time insert, label the root as BLACK
	}
}

bool RedBlackTree::isRed( TreeNode *root )
{
	if(root == NULL) return false;
	else return root->color == RED;
}

int RedBlackTree::size( TreeNode *root )
{
	if(root == NULL) return 0;
	else return root->N;
}

void RedBlackTree::insert( TreeNode *&root, int val )
{
	if(root == NULL) root = new TreeNode(val, RED, 1);
	if(val < root->val){
		insert(root->left, val);
	}else if(val > root->val){
		insert(root->right, val);
	}else{
		root->val = val;//overwrite the value
	}

	if(isRed(root->right) && !isRed(root->left)) root = rotateLeft(root);
	if(isRed(root->left) && root->left != NULL && isRed(root->left->left)) root = rotateRight(root);
	if(isRed(root->left) && isRed(root->right)) flipColors(root);
	root->N = size(root->left) + size(root->right) + 1;
}

bool RedBlackTree::search( TreeNode *root, int target )
{
	while(root != NULL){
		if(target == root->val){
			return true;
		}else if(target > root->val){
			return search(root->right, target);
		}else {
			return search(root->left, target);
		}
	}
	return false;
}

TreeNode* RedBlackTree::selectRank( TreeNode *root, int k )
{
	assert(root != NULL && k >= 0);

	int t = size(root->left);
	if(k > t) return selectRank(root->right, k - t - 1);
	else if(k < t) return selectRank(root->left, k);
	else return root;
}

int RedBlackTree::getRank( TreeNode *root, int target )
{
	if(root == NULL) return 0;

	if(target > root->val){
		return size(root->left) + 1 + getRank(root->right, target);
	}else if(target < root->val){
		return getRank(root->left, target);
	}else{
		return size(root->left);
	}
}

TreeNode* RedBlackTree::rotateLeft( TreeNode *root )
{
	assert(root != NULL && isRed(root->right));
	TreeNode *rc = root->right;
	root->right = rc->left;
	rc->left = root;
	rc->color = root->color;
	root->color = RED;

	//change N of the node
	rc->N = root->N;
	root->N = size(root->left) + size(root->right) + 1;
	return rc;
}

TreeNode* RedBlackTree::rotateRight( TreeNode *root )
{
	assert(root != NULL && isRed(root->left));
	TreeNode *lc = root->left;
	root->left = lc->right;
	lc->right = root;
	lc->color = root->color;
	root->color = RED;

	//change N of the node
	lc->N = root->N;
	root->N = size(root->left) + size(root->right) + 1;
	return lc;
}

void RedBlackTree::flipColors( TreeNode *root )
{
	assert(root != NULL && root->left != NULL && root->right != NULL);
	// h must have opposite color of its two children
	assert ((isRed(root) && !isRed(root->left) && !isRed(root->right))
		|| (!isRed(root) && isRed(root->left) && isRed(root->right)) );

	root->color = !root->color;
	root->left->color = !root->left->color;
	root->right->color = !root->right->color;
}

