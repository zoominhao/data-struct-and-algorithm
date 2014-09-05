#include "treetest.h"

vector<int> TreeTest::preorderTraversal( TreeNode *root )
{
	vector<int> preorder;
	if (root == NULL)
	{
		return preorder;
	}
	stack<TreeNode*> myStack;
	myStack.push(root);
	while (!myStack.empty())
	{
		root = myStack.top();
		preorder.push_back(root->val);
		myStack.pop();
		if (root->right != NULL)
		{
			myStack.push(root->right);
		}
		if (root->left != NULL)                    //attention: push right firstly
		{
			myStack.push(root->left);
		}
	}
	return preorder;
}


vector<int> TreeTest::preorderTraversal2( TreeNode *root )
{
	vector<int> preorder;
	if ( root == NULL)
	{
		return preorder;
	}
	preorder.push_back(root->val);
	if (root->left != NULL)
	{
		vector<int> lpreorder = preorderTraversal2(root->left);
		preorder.insert(preorder.end(), lpreorder.begin(), lpreorder.end());
	}
	if (root->right != NULL)
	{
		vector<int> rpreorder = preorderTraversal2(root->right);
		preorder.insert(preorder.end(), rpreorder.begin(), rpreorder.end());
	}
	return preorder;
}

vector<int> TreeTest::preorderTraversal3( TreeNode *root )
{
	vector<int> preorder;
	if (root == NULL)
	{
		return preorder;
	}

	preorderTraversalHelper( root, preorder );
	return preorder;
}


void TreeTest::preorderTraversalHelper( TreeNode* root, vector<int>& preorder )
{
	if(root != NULL)
	{
		preorder.push_back(root->val);
		preorderTraversalHelper( root->left, preorder );
		preorderTraversalHelper( root->right, preorder );
	}
}

vector<int> TreeTest::postorderTraversal( TreeNode* root )
{
	vector<int> postOrder;
	if (root == NULL)
	{
		return postOrder;
	}

    stack<TreeNode* > myStack;
	TreeNode* LNode = NULL;    //attention
	while (root != NULL || !myStack.empty())
	{
		while (root != NULL)
		{
			myStack.push(root);
			root = root->left;
		}
		root = myStack.top();
		if (root->right == NULL || root->right == LNode)
		{
			LNode = root;
			postOrder.push_back(root->val);
			myStack.pop();
			root = NULL;
		}
		else
		{
			root = root->right;
		}
	}
	
    return postOrder;
}

vector<int> TreeTest::postorderTraversal2( TreeNode* root )
{
	vector<int> postOrder;
	if (root == NULL) {
		return postOrder;
	}

	vector<int> lpostOrder = postorderTraversal2(root->left);
	postOrder.insert(postOrder.end(), lpostOrder.begin(), lpostOrder.end());               //attention:  end()   not begin()
	vector<int> rpostOrder = postorderTraversal2(root->right);
	postOrder.insert(postOrder.end(), rpostOrder.begin(), rpostOrder.end());
	postOrder.push_back(root->val);

	return postOrder;   
}

vector<int> TreeTest::inorderTraversal( TreeNode* root )
{
	vector<int> inOrder;
	if (root == NULL)
	{
		return inOrder;
	}
	stack<TreeNode* >  myStack;
	while (root != NULL || !myStack.empty())
	{
		while (root != NULL)
		{
			myStack.push(root);
			root = root->left;
		}
		if ( !myStack.empty() )
		{
			root = myStack.top();
			inOrder.push_back(root->val);
			myStack.pop();
			root = root->right;
		}
	}
	return inOrder;
}

vector<int> TreeTest::inorderTraversal2( TreeNode* root )
{
	vector<int> inOrder;
	if (root == NULL)
	{
		return inOrder;
	}

	vector<int> linOrder = inorderTraversal2(root->left);
	inOrder.insert(inOrder.end(), linOrder.begin(), linOrder.end());
	inOrder.push_back(root->val);
	vector<int> rinOrder = inorderTraversal2(root->right);
	inOrder.insert(inOrder.end(), rinOrder.begin(), rinOrder.end());
	return inOrder;
}

void TreeTest::testTraversal( void )
{
	//just test, if u want to build a tree, then use recursion
	//         3
	//     2        6
	//  5     1         4
	
	TreeNode* ll_leaf = new TreeNode(5); 
	TreeNode* lr_leaf = new TreeNode(1);
	TreeNode* rr_leaf = new TreeNode(4);
	TreeNode* l_node = new TreeNode(2, ll_leaf, lr_leaf);
	TreeNode* r_node = new TreeNode(6, NULL, rr_leaf);
	TreeNode* root = new TreeNode(3, l_node, r_node);
	//preorder:  3, 2, 5, 1, 6, 4
	vector<int> preorder = preorderTraversal3(root);
	cout<<"preOrder: "<<endl;
	for (size_t i = 0; i < preorder.size(); ++i)
	{
		cout<<preorder[i]<<" ";
	}
	cout<<endl;
	//inorder:  5, 2, 1, 3, 6, 4
	vector<int> inorder = inorderTraversal2( root );
	cout<<"inOrder: "<<endl;
	for (size_t i = 0; i < inorder.size(); ++i)
	{
		cout<<inorder[i]<<" ";
	}
	cout<<endl;
	//postorder: 5, 1, 2, 4, 6, 3
	vector<int> postorder = postorderTraversal2(root);
	cout<<"postOrder: "<<endl;
	for (size_t i = 0; i < postorder.size(); ++i)
	{
		cout<<postorder[i]<<" ";
	}
	cout<<endl;
	//level order: 3, 2, 6, 5, 1, 4
}

vector<vector<int>> TreeTest::levelOrder( TreeNode* root )
{
	vector<vector<int>> rst;
	if (root == NULL)
	{
		return rst;
	}
	queue<TreeNode*> que;
	que.push(root);

	while (!que.empty())
	{
		vector<int> level;
		int size = que.size();
		for (int i = 0; i < size; ++i)
		{
			TreeNode* head = que.front();
			level.push_back(head->val);
			if (head->left != NULL)
			{
				que.push(head->left);
			}
			if(head->right != NULL)
			{
				que.push(head->right);
			}
		}
		rst.push_back(level);
	}
	return rst;
}

int lastVal = INT_MIN;
bool TreeTest::isValidBST( TreeNode* root )
{
	if(root == NULL)
	{
		return true;
	}
	if (!isValidBST(root->left))
	{
		return false;
	}
	if (lastVal  >= root->val)
	{
		return false;
	}
	lastVal = root->val;
	if (!isValidBST(root->right))
	{
		return false;
	}
	return true;
}


bool TreeTest::isBalancedTree( TreeNode* root )
{
	int depth = 0;
	return isBalanced(root, depth);
}

bool TreeTest::isBalanced(TreeNode* root, int& depth)
{
	if(root == NULL)
	{
		depth = 0;
		return true;
	}
	int lh, rh;
	if(isBalanced(root->left,lh) && isBalanced(root->right,rh))
	{
		if(abs(lh - rh) <= 1)
		{
			depth = max(lh, rh) + 1;
			return true;
		}
	}
	return false;
}

void TreeTest::testValid( void )
{
	//just test, if u want to build a tree, then use recursion
	//         3
	//     2        6
	//  5     1         4

	/*TreeNode* ll_leaf = new TreeNode(5); 
	TreeNode* lr_leaf = new TreeNode(1);
	TreeNode* rr_leaf = new TreeNode(4);
	TreeNode* l_node = new TreeNode(2, ll_leaf, lr_leaf);
	TreeNode* r_node = new TreeNode(6, NULL, rr_leaf);
	TreeNode* root = new TreeNode(3, l_node, r_node);
	cout<<isBalancedTree(root)<<endl;*/
	//just test, if u want to build a tree, then use recursion
	//            3
	//      2           6
	//  5       1         
	//        4
	TreeNode* ll_leaf = new TreeNode(5); 
	TreeNode* lrl_leaf = new TreeNode(4); 
	TreeNode* lr_leaf = new TreeNode(1, lrl_leaf);
	TreeNode* l_node = new TreeNode(2, ll_leaf, lr_leaf);
	TreeNode* r_node = new TreeNode(6);
	TreeNode* root = new TreeNode(3, l_node, r_node);
	cout<<maxDepth(root)<<endl;

}

int TreeTest::minDepth( TreeNode* root )
{
	if(root == NULL)
	{
		return 0;
	}
	int lh = minDepth(root->left);
	int rh = minDepth(root->right);
	return min(lh, rh) + 1;
}

int TreeTest::maxDepth( TreeNode* root )
{
	if (root == NULL)
	{
		return 0;
	}
	int lh = maxDepth(root->left);
	int rh = maxDepth(root->right);
	return max(lh, rh) + 1;
}

bool TreeTest::isSameTree( TreeNode* root1, TreeNode* root2 )
{
	if (root1 == NULL && root2 == NULL)
	{
		return true;
	}
	if (root1 == NULL || root2 == NULL)
	{
		return false;
	}
	return ( root1->val == root2->val ) 
		&& isSameTree(root1->left, root2->left) 
		&& isSameTree(root1->right, root2->right);
}

bool TreeTest::isSymmetricTree( TreeNode* root )
{
	if (root == NULL)
	{
		return true;
	}
	return isSameTree(root->left, root->right);
}

void TreeTest::destroyTree( TreeNode* root )
{
	if(root == NULL)
	{
		return;
	}
	destroyTree(root->left);
	destroyTree(root->right);
	delete root;
}

void TreeTest::deleteBST( TreeNode* root, int target )
{
/*
	TreeNode* par = NULL;
	TreeNode* cur = root;
	while (cur != NULL)
	{
		if(target > cur->val)
		{
			par = cur;
			cur = cur->right;
		}
		else if (target < cur->val)
		{
			par = cur;
			cur = cur->left;
		}
		else
		{
			if(cur->left == NULL && cur->right == NULL)
			{
				delete cur;
				cur = NULL;
			}
		}
	}*/
}

bool TreeTest::insertBST( TreeNode* root, TreeNode* node)
{
	TreeNode* par = NULL;
	TreeNode* cur = root;
	while (cur != NULL)
	{
		if (cur->val > node->val)
		{
			par = cur;
			cur = cur->left;
		}
		else if(cur->val < node->val)
		{
			par = cur;
			cur = cur->right;
		}
		else
		{
			return false;
		}
	}
	if (par == NULL)
	{
		root = node;
	}
	else
	{
		if (cur->val > node->val)
		{
			cur->left = node;
		}
		else
		{
			cur->right = node;
		}
	}
	
	return true;
}

TreeNode* TreeTest::searchBST( TreeNode* root, int target)
{
	while (root != NULL)
	{
		if (root->val > target)
		{
			root = root->left;
		}
		else if (root->val < target)
		{
			root = root->right;
		}
		else
		{
            return root;
		}
	}
	return NULL;
}

void TreeTest::insertBST2( TreeNode* root, TreeNode* node )
{
	if (root == NULL)
	{
		root = node;
	}
	if (root->val > node->val)
	{
		insertBST2(root->left, node);
	}
	else if (root->val < node->val)
	{
        insertBST2(root->right, node);
	}
}

bool TreeTest::searchBST2( TreeNode* root, int target )
{
	if (root == NULL)
	{
		return false;
	}
	if (root->val > target)
	{
		return searchBST(root->left, target);
	}
	else if(root->val < target)
	{
		return searchBST(root->right, target);
	}
	else
	{
		return true;
	}
}







