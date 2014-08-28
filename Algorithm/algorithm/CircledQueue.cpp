#include "CircledQueue.h"

CircledQueue::CircledQueue()
{
	front = rear = 0;
}

CircledQueue::~CircledQueue()
{
	clear();
}

void CircledQueue::InQueue( int x )
{
	if((rear + 1) % MAXSIZE == front)
	{
		return;
	}
	data[rear] = x;
	rear = (rear + 1) % MAXSIZE;
}

int CircledQueue::OutQueue()
{
	if (rear == front)
	{
		return -1;
	}
	int e = data[front];
	front = (front + 1) % MAXSIZE;
}

bool CircledQueue::IsEmpty()
{
	return rear == front ? true : false;
}

int CircledQueue::length()
{
	return (rear - front + MAXSIZE) % MAXSIZE;
}

void CircledQueue::clear()
{
	front = rear = 0;
}

void CircledQueue::print()
{
	if (rear == front)
	{
		return;
	}
	else if(rear < front)
	{
		for (int i = front; i < MAXSIZE; ++i)
		{
			cout<<data[i];
		}
		for (int i = 0; i < rear; ++i)
		{
			cout<<data[i];
		}
		cout<<endl;
	}
	else
	{
		for (int i = front; i < rear; ++i)
		{
			cout<<data[i];
		}
		cout<<endl;
	}
}
