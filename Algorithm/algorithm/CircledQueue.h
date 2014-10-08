#pragma once
#include <iostream>
using namespace std;
#define  MAXSIZE 10
class CircledQueue
{
public:
	CircledQueue();
	~CircledQueue();
	void InQueue(int x);
	int OutQueue();
	bool IsEmpty();
	int length();
	void clear();
	void print();
private:
	int data[MAXSIZE];
	int front;
	int rear;
};