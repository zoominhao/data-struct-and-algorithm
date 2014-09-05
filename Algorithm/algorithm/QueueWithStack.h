#pragma once

#include <iostream>
#include <stack>
using namespace std;

class QueueWithStack
{
public:
	void push(int x);
	void pop();
	int front();
private:
	stack<int> inStk;
	stack<int> outStk;
};