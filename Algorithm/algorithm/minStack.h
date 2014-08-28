#pragma
#include <iostream>
#include <vector>

using namespace std;

class MinStack
{
public:
	void push(int x);
	void pop();
	int min();

private:
	vector<int>  minStack;
	vector<int>  dataStack;
};

class MinStack2
{
public:
	void push(int x);
	void pop();
	int min();

private:
	vector<int>  myStack;

};