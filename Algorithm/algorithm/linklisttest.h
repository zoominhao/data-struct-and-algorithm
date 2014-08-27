#include <iostream>

using namespace std;

struct ListNode 
{
	int val;
	ListNode *next;
	ListNode(int x, ListNode* nnext = NULL) : val(x), next(nnext) {}
};

class LinkListTest
{
public:
	//basic
	ListNode* del(ListNode* head, ListNode* toDel);
	void insert(ListNode* toInsert, int x);

	// Given a sorted linked list, delete all nodes that have duplicate numbers, leaving only distinct numbers from the original list. 
	// For example, Given 1->2->3->3->4->4->5, return 1->2->5. Given 1->1->1->2->3, return 2->3. 
	ListNode* deleteDuplicates(ListNode* head);
	// Given a sorted linked list, delete all duplicates such that each element appear only once. 
	// For example, Given 1->1->2, return 1->2. Given 1->1->2->3->3, return 1->2->3. 
	ListNode* deleteDuplicates2(ListNode* head);

	void testDeleteDuplicates( void );

	// Merge two sorted linked lists and return it as a new list. 
	// The new list should be made by splicing together the nodes of the first two lists. 
	ListNode* mergeTwoLists(ListNode* l1, ListNode* l2);

	// Given a linked list and a value x, partition it such that all nodes less than x come before nodes greater than or equal to x. 
	// You should preserve the original relative order of the nodes in each of the two partitions. 
	// For example, Given 1->4->3->2->5->2 and x = 3, return 1->2->2->4->3->5. 
    ListNode* partition(ListNode* head, int target);

	void testPartition( void );

	//reverse
	ListNode* reverse(ListNode* head);

	void testReverse( void );
	
	ListNode* findMiddle( ListNode* head );

	ListNode* findKth( ListNode* head, int k );

	//Sort a linked list in O(n log n) time using constant space complexity. 
	
	//remove the kth from end
	ListNode* removeKthFromEnd(ListNode* head, int k);

	void testRemoveKthFromEnd( void );
};  
