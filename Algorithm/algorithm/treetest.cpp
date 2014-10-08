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
	//zigzag level order: 3, 6, 2, 5, 1, 4
	vector<vector<int>> zigzag = zigZagLevelOrder(root);
	cout<<"zigzag level order"<<endl;
	for (int i = 0; i < zigzag.size(); ++i)
	{
		for (int j = 0; j< zigzag[i].size(); ++j)
		{
			cout<<zigzag[i][j]<<" ";
		}
		cout<<endl;
	}
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
			que.pop();
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
	if (lh == 0)
	{
		return rh + 1;
	}
	else if (rh == 0)
	{
		return lh + 1;
	}
	else
	{
		return min(lh, rh) + 1;
	}
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

bool TreeTest::deleteBST( TreeNode* root, int target )
{
	if (root == NULL)
	{
		return false;
	}
	if(root->val > target)
	{
		return deleteBST(root->left, target);
	}
	else if (root->val < target)
	{
		return deleteBST(root->right, target);
	}
	else
	{
		return deleteNode(root);
	}
}


bool TreeTest::deleteNode( TreeNode* node)
{
	TreeNode *par;
	if(node->left == NULL)
	{
		par = node;
		node = node->right;
		free(par);
	}
	else if(node->right == NULL)
	{
		par = node;
		node = node->left;
		free(par);
	}
	else
	{
		par = node;
		TreeNode* tmp = node->left;
		while(tmp->right != NULL)
		{
			par = tmp;
			tmp = tmp->right;
		}
		node->val = tmp->val;
		if(par == node)
		{
			par->left = tmp->left;
		}
		else
		{
			par->right = tmp->left;
		}
		free(tmp);
	}
	return true;
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
		if (par->val > node->val)
		{
			par->left = node;
		}
		else
		{
			par->right = node;
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

vector<int> TreeTest::DFS( TreeNode* root )
{
	vector<int> rst;
	if(root == NULL)
		return rst;
	stack<TreeNode* > stk;
	stk.push(root);

	while(!stk.empty())
	{
		root = stk.top();
		rst.push_back(root->val);
		stk.pop();
		if(root->right != NULL)
			stk.push(root->right);
		if(root->left != NULL)
			stk.push(root->left);
	}
	return rst;
}

vector<int> TreeTest::BFS( TreeNode* root )
{
	vector<int> rst;
	if(root == NULL)
		return rst;
	queue<TreeNode* > que;
	que.push(root);

	while (!que.empty())
	{
		root = que.front();
		rst.push_back(root->val);
		que.pop();
		if(root->left != NULL)
			que.push(root->left);
		if(root->right != NULL)
			que.push(root->right);
	}
	return rst;

}

bool TreeTest::isSubTree( TreeNode* T1, TreeNode* T2 )
{
	if(T1 == NULL)
		return false;
	if(isSameTree(T1, T2))
		return true;
	return isSubTree(T1->left, T2) || isSubTree(T1->right, T2);
}

TreeNode* TreeTest::buildTreeFromInandPost( vector<int>& inOrder, vector<int>& postOrder )
{
	if(inOrder.size() == 0 || postOrder.size() != inOrder.size())
	{
		return NULL;
	}
	return buildIPHelper(inOrder.begin(), inOrder.end(), postOrder.begin(), postOrder.end());
}

TreeNode* TreeTest::buildIPHelper( vector<int>::iterator inL, vector<int>::iterator inR, vector<int>::iterator postL, vector<int>::iterator postR )
{
	if (postL >= postR)
	{
		return NULL;
	}
	int val = *(--postR);
	vector<int>::iterator cur = find(inL, inR, val);
	int lsize = cur - inL;

	TreeNode* root = new TreeNode(val);

	root->left = buildIPHelper(inL, cur, postL, postL + lsize);
	root->right = buildIPHelper(cur + 1, inR, postL + lsize, postR);
	return root;
}

TreeNode* TreeTest::buildTreeFromPreandIn( vector<int>& preOrder, vector<int>& inOrder )
{
	if(preOrder.size() == 0 || preOrder.size() != inOrder.size())
	{
		return NULL;
	}

	return buildPIHelper(preOrder.begin(), preOrder.end(), inOrder.begin(), inOrder.end());
}

TreeNode* TreeTest::buildPIHelper( vector<int>::iterator preL, vector<int>::iterator preR, vector<int>::iterator inL, vector<int>::iterator inR )
{
	if(preL >= preR)
	{
		return NULL;
	}

	int val = *(preL++);
	vector<int>::iterator cur = find(inL, inR, val);
	int rsize = inR - cur;

	TreeNode* root = new TreeNode(val);
	root->left = buildPIHelper(preL, preR - rsize, inL, cur);
	root->right = buildPIHelper(preR - rsize, preR, cur + 1, inR);

	return root;
}

vector<vector<int>> TreeTest::zigZagLevelOrder( TreeNode* root )
{
	vector<vector<int>>  rst;
	if(root == NULL)
	{
		return rst;
	}

	stack<TreeNode* > curStk;
	
	curStk.push(root);
	bool isNormal = true;
	while (!curStk.empty())
	{
		vector<int> curRst;
		stack<TreeNode* > nextStk;
		while (!curStk.empty())
		{
			TreeNode* root = curStk.top();
			curStk.pop();
			curRst.push_back(root->val);

			if(isNormal)
			{
				if(root->left != NULL)
				{
					nextStk.push(root->left);
				}
				if(root->right != NULL)
				{
					nextStk.push(root->right);
				}
			}
			else
			{
				if(root->right != NULL)
				{
					nextStk.push(root->right);
				}
				if(root->left != NULL)
				{
					nextStk.push(root->left);
				}
			}
		}
		isNormal = !isNormal;
		curStk = nextStk;

		rst.push_back(curRst);
	}
	return rst;
}

vector<int> TreeTest::rangeSearchOnBST( TreeNode* root, int k1, int k2 )
{
	vector<int> rst;
	if(root == NULL)
	{
		return rst;
	}

	if(k1 < root->val)
	{
		vector<int> lrst = rangeSearchOnBST(root->left, k1, k2);
		rst.insert(rst.end(), lrst.begin(), lrst.end());
	}
	if(k1 <= root->val && k2 >= root->val)
	{
		rst.push_back(root->val);
	}
	if(k2 > root->val)
	{
		vector<int> rrst = rangeSearchOnBST(root->right, k1, k2);
		rst.insert(rst.end(), rrst.begin(), rrst.end());
	}
	return rst;
}



void TreeTest::testSearch( void )
{
	//just test, if u want to build a tree, then use recursion
	//         20
	//     8        22
	//  4     12         24

	TreeNode* ll_leaf = new TreeNode(4); 
	TreeNode* lr_leaf = new TreeNode(12);
	TreeNode* rr_leaf = new TreeNode(24);
	TreeNode* l_node = new TreeNode(8, ll_leaf, lr_leaf);
	TreeNode* r_node = new TreeNode(22, NULL, rr_leaf);
	TreeNode* root = new TreeNode(20, l_node, r_node);

	vector<int> rst = rangeSearchOnBST(root, 10, 22);
	for (int i = 0; i < rst.size(); ++i)
	{
		cout<<rst[i]<<" ";
	}
	cout<<endl;
}

bool TreeTest::isCover( TreeNode* root, TreeNode* node )
{
	if(root == NULL)
		return false;
	if(root == node)
		return true;
	return isCover(root->left, node) || isCover(root->right, node);
}

TreeNode* TreeTest::lca( TreeNode* root, TreeNode* node1, TreeNode* node2 )
{
	if(root == NULL || node1 == NULL || node2 == NULL)
	{
		return NULL;
	}

	if (isCover(root->left, node1) && isCover(root->left, node2))
	{
		return lca(root->left, node1, node2);
	}
	if (isCover(root->right, node1) && isCover(root->right, node2))
	{
		return lca(root->right, node1, node2);
	}
	return root;
}

TreeNode* TreeTest::lcaBST( TreeNode* root, TreeNode* node1, TreeNode* node2 )
{
	if(root == NULL || node1 == NULL || node2 == NULL)
	{
		return NULL;
	}

	if(min(node1->val, node2->val)  > root->val)
	{
		return lcaBST(root->right, node1, node2);
	}
	if(max(node1->val, node2->val)  < root->val)
	{
		return lcaBST(root->left, node1, node2);
	}
	return root;
}










