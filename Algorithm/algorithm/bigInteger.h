#pragma once

#include <iostream>
using namespace std;
const int N = 210;
class BigInteger
{
public:
	void add(int num1[], int num2[], int num3[]);
	void sub(int num1[], int num2[], int num3[]);
	void multiple(int num1[], int num2[], int num3[]);

	void print(int num[]);

	void testBigInteger( void );
};