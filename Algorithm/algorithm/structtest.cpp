#include "structtest.h"
#include <stack>
#include <queue>
#include <functional>

int StructTest::largestRectangleArea( int* height, int n )
{
	if(height == NULL || n == 0)
	{
		return 0;
	}
	stack<int> stk;
	int maxArea = 0;
	for (int i = 0; i <= n; i++)
	{
		int cur = (i == n) ? -1 : height[i];
		while (!stk.empty() && cur <= height[stk.top()])
		{
			int h = height[stk.top()];
			stk.pop();
			int w = stk.empty() ? i : i - stk.top() - 1;
			maxArea = max(maxArea, h*w);
		}
		stk.push(i);
	}
	return maxArea;
}

void StructTest::testLRA( void )
{
	int arr[] = {1, 3, 2, 5, 6, 1, 2, 3};
	cout<<"Max Area: "<<largestRectangleArea(arr, sizeof(arr) / sizeof(int))<<endl;
}

const int HASH_TABLE_SIZE = 10;

int StructTest::hashfunc( string key )
{
	int sum = 0;
	for (int i = 0; i < key.length(); ++i)
	{
		sum = sum * 33 + (int)(key.at(i));
		sum = sum % HASH_TABLE_SIZE;
	}
	return sum;
}

int StructTest::longestConsecutive( vector<int> &num )
{
	if(num.size() == 0)
		return 0;
	map<int, int> hs;
	for (int i = 0; i < num.size(); ++i)
	{
		hs.insert(pair<int, int>(num[i], 0));
	}
	int maxl = 1;
	for (int i = 0; i < num.size(); ++i)
	{
		if(hs[num[i]] == 1)
			continue;
		int tmp = num[i];
		int len = 1;

		while(hs.find(tmp + 1) != hs.end())
		{
			len++;
			tmp++;
			hs[tmp] = 1;
		}
		tmp = num[i];
		while(hs.find(tmp - 1) != hs.end())
		{
			len++;
			tmp--;
			hs[tmp] = 1;
		}
		maxl = max(maxl, len);
	}
	return maxl;
}

void StructTest::testLongestConsecutive( void )
{
	int arr[] = {2, 6, 9, 4, 3, 5};
	vector<int> vec;
	vec.insert(vec.end(), arr, arr + sizeof(arr) / sizeof(int));
	cout<<"longest consecutive: "<<longestConsecutive(vec)<<endl;
}

void StructTest::heapMaintainMedian()
{
	priority_queue<int, vector<int>, less<int>> max_heap;
	priority_queue<int, vector<int>, greater<int>> min_heap;
	int x;
	double mid = INT_MAX;
	while (cin >> x && x)
	{
		if (mid == INT_MAX)
		{
			max_heap.push(x);
			mid = x;
			cout<<"mid is: "<<mid<<endl;
			continue;
		}

		if (x <= mid)
		{
			max_heap.push(x);
		}
		else
		{
			min_heap.push(x);
		}
		int left = max_heap.size();
		int right = min_heap.size();
		int tmp = 0;

		if (left == right)
		{
			mid = ((max_heap.top() + min_heap.top()) / 2.0);
		}
		else if (abs(left - right) == 1)
		{
			tmp = (left > right) ? max_heap.top() : min_heap.top();
			mid = tmp;
		}
		else if (left - right == 2)
		{
			tmp = max_heap.top();
			max_heap.top();
			min_heap.push(tmp);
			mid = ((max_heap.top() + min_heap.top()) / 2.0);
		}
		else if (right - left == 2)
		{
			tmp = min_heap.top();
			min_heap.pop();
			max_heap.push(tmp);
			mid = ((max_heap.top() + min_heap.top()) / 2.0);
		}
		cout<<"mid is: "<<mid <<endl;
	}

}

LRUCache::LRUCache( int capacity )
{
	head = new Node(-1, -1);
	tail = new Node(-1, -1);
	m_capacity = capacity;
	tail->prev = head;
	head->next = tail;
}

int LRUCache::get( int key )
{
	if(hs.find(key) == hs.end())
	{
		return -1;
	}
	else
	{
		
		Node* current = hs[key];
		current->prev->next = current->next;
		current->next->prev = current->prev;
		move_to_tail( hs[key] );

		return hs[key]->value;
	}

}

void LRUCache::set( int key, int value )
{
	if (hs.find(key) != hs.end())
	{
		hs[key]->value = value;
		return;
	}
	else
	{
		Node* current = new Node(key, value);
		if (hs.size() == m_capacity)
		{
			hs.erase(head->next->key);
			head->next = head->next->next;
			head->next->prev = head;
		}
		hs.insert(pair<int, Node*>(key, current));
		move_to_tail(current);
	}
	
}

void LRUCache::move_to_tail( Node* current )
{
	current->prev = tail->prev;
	tail->prev->next = current;
	tail->prev = current;
	current->next = tail;
}


