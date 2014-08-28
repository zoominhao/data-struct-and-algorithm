#include "minStack.h"

void MinStack::push(int x)
{
	dataStack.push_back(x);
	if(minStack.empty())
	{
		minStack.push_back(x);
	}
	else if(x > minStack[minStack.size() - 1 ])
	{
		minStack.push_back(minStack[minStack.size() - 1 ]);
	}
	else
	{
		minStack.push_back(x);
	}
}

void MinStack::pop()
{
	if (dataStack.empty())
	{
		cout<<"error"<<endl;
		return;
	}
	dataStack.pop_back();
	minStack.pop_back();
}

int MinStack::min()
{
	if (minStack.empty())
	{
		cout<<"error"<<endl;
		return -1;
	}
	return minStack[minStack.size() - 1 ];
}

void MinStack2::push(int x)
{
	
	if (myStack.empty())
	{
		myStack.push_back(x);
		myStack.push_back(x);
	}
	else if(x > myStack[myStack.size() - 1])
	{
		int min = myStack[myStack.size() - 1];
		myStack.push_back(x);
		myStack.push_back(min);
	}
	else
	{
		myStack.push_back(x);
		myStack.push_back(x);
	}
}

void MinStack2::pop()
{
	if (myStack.empty())
	{
		cout<<"error"<<endl;
		return;
	}
	myStack.pop_back();
	myStack.pop_back();
}

int MinStack2::min()
{
	if (myStack.empty())
	{
		cout<<"error"<<endl;
		return -1;
	}
	return myStack[myStack.size() - 1];
}
