#pragma once
#include <iostream>
#include <queue>
using namespace std;

class StackWithQueue
{
public:
	void push(int x);
	void pop();
	int top();
private:
	queue<int> que1;
	queue<int> que2;
};
