#include "linklisttest.h"

#include <map>


ListNode* LinkListTest::deleteDuplicates( ListNode* head )
{
	if(head == NULL || head->next == NULL)
	{
       return head;
	}
	ListNode* dummy = new ListNode(0);
	dummy->next = head;
	head = dummy;

	int val;
	while (head->next != NULL && head->next->next != NULL)
	{
		if (head->next->val == head->next->next->val)
		{
			val = head->next->val;
			while (head->next != NULL && head->next->val == val)
			{
				head->next = head->next->next;
			}
		}
		else
		{
			head = head->next;
		}
	}

	return dummy->next;
}

ListNode* LinkListTest::deleteDuplicates2( ListNode* head )
{
	if (head == NULL)
	{
		return head;
	}

	ListNode* dummy = head;

	while (head->next != NULL)
	{
		 if(head->val == head->next->val)
		 {
			 head->next = head->next->next;
		 }
		 else
		 {
             head = head->next;
		 }
	}
	return dummy;
}


void LinkListTest::testDeleteDuplicates( void )
{
	//int num[] = {1, 1, 2, 2, 3, 3, 3, 15};
	int num[] = {1, 1, 2};
	ListNode* pt, *current;
	pt = (ListNode*)malloc(sizeof(ListNode));
	current = pt;
	int i;
	for(i = 0; i < sizeof(num) / sizeof(int); i++)
	{
		ListNode* tmp =  (ListNode*) malloc(sizeof(ListNode));
		tmp -> val = num[i];
		current  -> next  = tmp;
		current =  current -> next;
	}
	current -> next  = NULL;

	//pt = deleteDuplicates2(pt->next);
	pt = del( pt->next, pt->next->next->next );

	while(pt != NULL)
	{
		cout<<pt->val<<" ";
		pt = pt->next;
	}
	cout<<endl;
}

ListNode* LinkListTest::sortList( ListNode* head )
{
	if(head == NULL || head->next == NULL)
	{
		return head;
	}

	ListNode* mid = findMiddle(head);
	ListNode* l1 = head;
	ListNode* l2 = mid->next;
	mid->next = NULL;
	l1 = sortList(l1);
	l2 = sortList(l2);

	return mergeTwoLists(l1, l2);
}

ListNode* LinkListTest::mergeTwoLists( ListNode* l1, ListNode* l2 )
{
	ListNode* dummy = new ListNode(0);
	ListNode* lastNode = dummy;

	while (l1 != NULL && l2 != NULL)
	{
		if (l1->val < l2->val)
		{
			lastNode->next = l1;
			l1 = l1->next;
		}
		else
		{
			lastNode->next = l2;
			l2 = l2->next;
		}
		lastNode = lastNode->next;
	}
	if (l1 != NULL)
	{
		lastNode->next = l1;
	}
	if(l2 != NULL)
	{
		lastNode->next = l2;
	}
	delete lastNode;
	return dummy->next;
}

ListNode* LinkListTest::insertAtHead(ListNode* head, int x)
{
	ListNode* np = new ListNode(x, head);
	return np;

}

ListNode* LinkListTest::insertAtTail(ListNode* head, int x)
{
	ListNode dummy(-1);
	dummy.next = head;

	ListNode *p = &dummy;
	while (p->next != NULL)
	{
		p = p->next;
	}
	ListNode* np = new  ListNode(x);
	np->next = p;
	return dummy.next;
}

ListNode* LinkListTest::del( ListNode* head, ListNode* toDel )
{
	if (head == NULL || toDel==NULL)
	{
		return head;
	}
	if (toDel->next != NULL)
	{
		toDel->val = toDel->next->val;
		ListNode *tmp = toDel->next;
		toDel->next = toDel->next->next;
		delete tmp;
		return head;
	}
	else
	{
		ListNode* dummy = new ListNode(0);
		dummy->next = head;
		head = dummy;
		while (head != NULL && head->next != toDel)
		{
			head = head->next;
		}
		if (head == NULL)
		{
			return dummy->next;
		}

		head->next = NULL;
		delete toDel;
		return dummy->next;
	}
}

ListNode* LinkListTest::partition( ListNode* head, int target )
{
	if (head == NULL)
	{
		return head;
	}
	ListNode* ldummy = new ListNode(0);
	ListNode* rdummy = new ListNode(0);
	ListNode* left = ldummy;
	ListNode* right = rdummy;
	while (head != NULL)
	{
		if (head->val < target)
		{
			left->next = head;
			left = left->next;
		}
		else
		{
			right->next = head;
			right = right->next;
		}
		head = head->next;
	}
	right->next = NULL;
	left->next = rdummy->next;
	delete rdummy, right, left;
	return ldummy->next;
}

void LinkListTest::testPartition( void )
{
	int num[] = {1, 4, 3, 2, 5, 2};
	ListNode* pt, *current;
	pt = (ListNode*)malloc(sizeof(ListNode));
	current = pt;
	int i;
	for(i = 0; i < sizeof(num) / sizeof(int); i++)
	{
		ListNode* tmp =  (ListNode*) malloc(sizeof(ListNode));
		tmp -> val = num[i];
		current  -> next  = tmp;
		current =  current -> next;
	}
	current -> next  = NULL;

	pt = partition(pt->next, 3);

	while(pt != NULL)
	{
		cout<<pt->val<<" ";
		pt = pt->next;
	}
	cout<<endl;
}

ListNode* LinkListTest::reverse( ListNode* head )
{
	ListNode* pre = NULL;
	ListNode* cur = head;
	ListNode* next = NULL;
	while (cur != NULL)
	{
		 next = cur->next;
		 cur->next = pre;
		 pre = cur;
		 cur = next;
	}
	return pre;
}

void LinkListTest::testReverse( void )
{
	int num[] = {1, 4, 3, 2, 5, 2};
	ListNode* pt, *current;
	pt = (ListNode*)malloc(sizeof(ListNode));
	current = pt;
	int i;
	for(i = 0; i < sizeof(num) / sizeof(int); i++)
	{
		ListNode* tmp =  (ListNode*) malloc(sizeof(ListNode));
		tmp -> val = num[i];
		current  -> next  = tmp;
		current =  current -> next;
	}
	current -> next  = NULL;

	pt = reverse(pt->next);

	while(pt != NULL)
	{
		cout<<pt->val<<" ";
		pt = pt->next;
	}
	cout<<endl;
}

ListNode* LinkListTest::findMiddle( ListNode* head )
{
	if (head == NULL || head->next == NULL)
	{
		return head;
	}
	ListNode* p1 = head;
	ListNode* p2 = head;
	while(p2->next !=NULL && p2->next->next != NULL)
	{
		p1 = p1->next;
		p2 = p2->next->next;
	}
	return p1;
}

ListNode* LinkListTest::findKth( ListNode* head, int k )
{
	if (head == NULL)
	{
		return NULL;
	}
	
	while ( k-- > 0 && head != NULL )
	{
		head = head->next;
	}
	return head;
}

ListNode* LinkListTest::removeKthFromEnd( ListNode* head, int k )
{
	if (head == NULL || head->next == NULL )
	{
		return NULL;
	}
	if (k <= 0)
	{
		return head;
	}

	ListNode* p1 = head;
	ListNode* p2 = head;
	ListNode* pre = new ListNode(0);
	pre->next = head;
	while(k-- > 0)
	{
		p1 = p1->next;
	}
	while(p1 != NULL)
	{
		p1 = p1->next;
		pre = p2;
		p2 = p2->next;
	}

	pre->next = pre->next->next;
	return head;
}

void LinkListTest::testRemoveKthFromEnd( void )
{
	int num[] = {1, 4, 3, 2, 5, 2};
	ListNode* pt, *current;
	pt = (ListNode*)malloc(sizeof(ListNode));
	current = pt;
	int i;
	for(i = 0; i < sizeof(num) / sizeof(int); i++)
	{
		ListNode* tmp =  (ListNode*) malloc(sizeof(ListNode));
		tmp -> val = num[i];
		current  -> next  = tmp;
		current =  current -> next;
	}
	current -> next  = NULL;

	pt = removeKthFromEnd(pt->next, 3);

	while(pt != NULL)
	{
		cout<<pt->val<<" ";
		pt = pt->next;
	}
	cout<<endl;
}

ListNode* LinkListTest::detectCycle( ListNode* head )
{
	if (head == NULL)
	{
		return NULL;
	}
	ListNode* slow = head;
	ListNode* fast = head;
	while (fast->next != NULL && fast->next->next != NULL)
	{
		slow = slow->next;
		fast = fast->next->next;
		if (slow == fast)
		{
			break;
		}
	}
	if (fast == NULL)
	{
		return NULL;
	}
	fast = head;
	while (fast != slow)
	{
		fast = fast->next;
		slow = slow->next;
	}
	return fast;
}

ListNode* LinkListTest::reorderList( ListNode* head )
{
	if(head == NULL)
		return head;
	ListNode* mid = findMiddle(head);
	ListNode* l1 = head;
	ListNode* l2 = mid->next;
	mid->next = NULL;
	l2 = reverse(l2);
	ListNode* dummy = new ListNode(0);
	ListNode* cur = dummy;
	int count = 0;
	while (l1 != NULL && l2 != NULL)
	{
		if (count % 2 == 0)
		{
			dummy->next = l1;
			l1 = l1->next;
		}
		else
		{
			dummy->next = l2;
			l2 = l2->next;
		}
		dummy = dummy->next;
		count++;
	}
	if(l1 != NULL)
	{
		dummy->next = l1;
	}
	if(l2 != NULL)
	{
		dummy->next = l2;
	}
	return cur->next;
}

void LinkListTest::testReorderList( void )
{
	int num[] = {1, 4, 3, 2, 5, 8};
	
	ListNode* cur = new ListNode(0);
	ListNode* head = cur;

	for(int i = 0; i < sizeof(num) / sizeof(int); i++)
	{
		ListNode* tmp =  new ListNode(num[i]);
		cur->next  = tmp;
		cur= cur->next;
	}
	cur->next = NULL;

	ListNode* reoderList = reorderList(head->next);

	while(reoderList != NULL)
	{
		cout<<reoderList->val<<" ";
		reoderList = reoderList->next;
	}
	cout<<endl;
}


RandomListNode* LinkListTest::copyRandomListByHash( RandomListNode* head )
{
	if(head == NULL)
	{
		return NULL;
	}
	map<RandomListNode*, RandomListNode*> hs;
	RandomListNode* dummy = new RandomListNode(0);
	RandomListNode* pre = dummy->next;
	RandomListNode* newNode;
	while(head != NULL)
	{
		if(hs.find(head) != hs.end())
		{
			newNode = hs[head];
		}
		else
		{
			newNode = new RandomListNode(head->val);
			hs.insert(pair<RandomListNode*, RandomListNode*>(head, newNode));
		}
		pre->next = newNode;

		if(hs.find(head->random) != hs.end())
		{
			newNode->random = hs[head->random];
		}
		else
		{
			newNode->random = new RandomListNode(head->random->val);
			hs.insert(pair<RandomListNode*, RandomListNode*>(head->random, newNode));
		}
		pre = pre->next;
		head = head->next;
	}
	return dummy->next;
}

RandomListNode* LinkListTest::copyRandomList( RandomListNode* head )
{
	if(head == NULL)
	{
		return NULL;
	}
	copyNext(head);
	copyRandom(head);
	return spliList(head);
}

void LinkListTest::copyNext( RandomListNode* head )
{
	while(head != NULL)
	{
		RandomListNode* newNode = new RandomListNode(head->val);
		newNode->random = head->random;
		newNode->next = head->next;
		head->next = newNode;
		head = head->next->next;
	}
}

void LinkListTest::copyRandom( RandomListNode* head )
{
	while(head != NULL)
	{
		if(head->next->random != NULL)
		{
			head->next->random = head->random->next;
		}
		head = head->next->next;
	}
}

RandomListNode* LinkListTest::spliList( RandomListNode* head )
{
	RandomListNode* newHead = head->next;
	while (head != NULL)
	{
		RandomListNode* tmp = head->next;
		head->next = tmp->next;
		head = head->next;
		if (head != NULL)
		{
			tmp->next = head;
		}
	}
	return newHead;
}

TreeNode* LinkListTest::sortedListToBST( ListNode *head )
{
	if(head == NULL)
		return NULL;
	int size = 0;
	ListNode* cur = head;
	while(head != NULL)
	{
		head = head->next;
		size++;
	}

	return sortedListToBSTHelper(head, size);
}

TreeNode* LinkListTest::sortedListToBSTHelper(ListNode* head, int size)
{
	if(size <= 0)
		return NULL;

	TreeNode* root;
	root->left = sortedListToBSTHelper(head, size / 2);
	root = new TreeNode(head->val);
	head = head->next;
	root->right = sortedListToBSTHelper(head, size - 1 - size / 2);

	return root;
}





