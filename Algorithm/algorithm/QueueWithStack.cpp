#include "QueueWithStack.h"

void QueueWithStack::push(int x)
{
	inStk.push(x);
}

void QueueWithStack::pop()
{
	if (!outStk.empty())
	{
		outStk.pop();
	}
	else
	{
		while (!inStk.empty())
		{
			outStk.push(inStk.top());
			inStk.pop();
		}
		if (!outStk.empty())
		{
			outStk.pop();
		}
	}
}

int QueueWithStack::front()
{
	if (!outStk.empty())
	{
		return outStk.top();
	}
	else
	{
		while (!inStk.empty())
		{
			outStk.push(inStk.top());
			inStk.pop();
		}
		if (!outStk.empty())
		{
			return outStk.top();
		}
		else
		{
           return INT_MAX;
		}
	}
}



