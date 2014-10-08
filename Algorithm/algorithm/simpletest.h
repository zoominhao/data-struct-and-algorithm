#pragma once
#include <iostream>
#include <vector>
#include <string>
using namespace std;

struct Date
{
	int year;
	int month;
	int day;
};

class SimpleTest
{
public:
	int getAbsDays(Date date);
	int getDateDiff(Date date1, Date date2);

	void testDaysDiff(void);

	int gcd(int num1, int num2);
	void testGcd( void );
	//sqrt
	double mySqrt(double num);
	double mySqrt2(double num);
	void testSqrt( void );

	//high frequence
	//single number
	//Given an array of integers, every element appears twice except for one. Find that single one
	int singleNumber(int A[], int n);
	//Given an array of integers, every element appears three times except for one. Find that single one.
	int singleNumber2(int A[], int n);
	//Given an array of integers, every element appears twice except for two. Find the two singles
	int* twoSingleNumber(int A[], int n);

    void testSignleNumber(void);

	//majority number
	int majorityNumber(int A[], int n);
	int majorityNumber2(int A[], int n);
	int majorityNumber3(int A[], int n, int k);

	void testMajorityNumber(void);

    //best time to buy and sell stock
	// Say you have an array for which the ith element is the price of a given stock on day i.
	// If you were only permitted to complete at most one transaction 
	// (ie, buy one and sell one share of the stock), design an algorithm to find the maximum profit.
	int maxProfit(int price[], int n );
	// Design an algorithm to find the maximum profit. You may complete as many transactions as you like
	// (ie, buy one and sell one share of the stock multiple times). However, you may not engage in multiple transactions at the same time 
	// (ie, you must sell the stock before you buy again).
	int maxProfit2(int price[], int n);
	// Design an algorithm to find the maximum profit. You may complete at most two transactions.
	int maxProfit3(int price[], int n);
	void testMaxProfit(void);

	//subarray
	int maxSubArray(int A[], int n);
	int maxTwoSubArray(int A[], int n);

	int maxProduct(int A[], int n);
	//str2int
	int  str2int(string str);
	//int2str
	string int2str(int a);
	void testtransfer(void);
};