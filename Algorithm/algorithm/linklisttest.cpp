#include "linklisttest.h"

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
	int num[] = {1, 1, 2, 2, 3, 3, 3, 15};
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
	//pt = del( pt->next, pt->next->next );

	while(pt != NULL)
	{
		cout<<pt->val<<" ";
		pt = pt->next;
	}
	cout<<endl;
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

void LinkListTest::insert(ListNode* toInsert, int x )
{
	if (toInsert == NULL)
	{
		return;
	}

	toInsert->next = new ListNode(x,toInsert->next);
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
		toDel->next = toDel->next->next;
		ListNode *tmp = toDel->next;
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
			return head;
		}
		ListNode *tmp = toDel;
		head->next = NULL;
		delete tmp;
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
