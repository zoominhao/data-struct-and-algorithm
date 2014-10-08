#pragma once
#include <iostream>
#include <map>
#include <vector>

using namespace std;

class StructTest
{
public:
	//largest rectangle in histogram
	//Given n non-negative integers representing the histogram's bar height where the width of each bar is 1, 
	// find the area of largest rectangle in the histogram. For example, Given height = [2,1,5,6,2,3], return 10.
	int largestRectangleArea(int* height, int n);
	void testLRA(void);

	//APR hashfunc  - Magic Number 33
	int hashfunc(string key);

	//Longest Consecutive Sequence 
	//Given an unsorted array of integers, find the length of the longest consecutive elements sequence.
	//Given [100, 4, 200, 1, 3, 2],The longest consecutive elements sequence is [1, 2, 3, 4].
	//Return its length: 4.
	int longestConsecutive(vector<int> &num);

	void testLongestConsecutive(void);

	//heapMaintainMedian
	void heapMaintainMedian();
};

// Least Recently Used (LRU) cache
struct Node
{
	Node* prev;
	Node* next;
	int   key;
	int   value;

	Node(int k, int v):key(k), value(v), prev(NULL), next(NULL) {}
};
class LRUCache
{
public:
	LRUCache(int capacity);
	int get(int key);
	void set(int key, int value);
private:
	void move_to_tail(Node* current);

private:
	int		m_capacity;
	map<int, Node*> hs;
	Node* head;
	Node* tail;
};