#include <iostream>
#include "treetest.h"

using namespace std;

struct ListNode 
{
	int val;
	ListNode *next;
	ListNode(int x, ListNode* nnext = NULL) : val(x), next(nnext) {}
};

struct RandomListNode
{
	int val;
	RandomListNode *next, *random;
	RandomListNode(int x) : val(x), next(NULL), random(next) {}
};

class LinkListTest
{
public:
	//basic
	ListNode* insertAtHead(ListNode* head, int x);
	ListNode* insertAtTail(ListNode* head, int x);
	ListNode* del(ListNode* head, ListNode* toDel);

	// Given a sorted linked list, delete all nodes that have duplicate numbers, leaving only distinct numbers from the original list. 
	// For example, Given 1->2->3->3->4->4->5, return 1->2->5. Given 1->1->1->2->3, return 2->3. 
	ListNode* deleteDuplicates(ListNode* head);
	// Given a sorted linked list, delete all duplicates such that each element appear only once. 
	// For example, Given 1->1->2, return 1->2. Given 1->1->2->3->3, return 1->2->3. 
	ListNode* deleteDuplicates2(ListNode* head);

	void testDeleteDuplicates( void );

	//merge sort
	ListNode* sortList(ListNode* head);
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
	//detect cycle
	ListNode* detectCycle(ListNode* head);

	//reoder list
	//Given a singly linked list L: L0¡úL1¡ú¡­¡úLn-1¡úLn, reorder it to: L0¡úLn¡úL1¡úLn-1¡úL2¡úLn-2¡ú¡­ 
	//You must do this in-place without altering the nodes' values. 
	//For example, {1,2,3,4}, reorder it to {1,4,2,3}.
	ListNode* reorderList(ListNode* head);

	void testReorderList(void);

	//Copy List with Random Pointer
	//A linked list is given such that each node contains an additional random pointer which 
	//could point to any node in the list or null. Return a deep copy of the list.
	RandomListNode* copyRandomListByHash(RandomListNode* head);
	RandomListNode* copyRandomList(RandomListNode* head);
	void copyNext(RandomListNode* head);
	void copyRandom(RandomListNode* head);
	RandomListNode* spliList(RandomListNode* head);

	//Given a singly linked list where elements are sorted in ascending order, convert it to a height balanced BST.
	TreeNode* sortedListToBST(ListNode *head); 
	TreeNode* sortedListToBSTHelper(ListNode* head, int size);
};  
