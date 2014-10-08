#pragma once

#include <iostream>
#include <vector>
using namespace std;

class SortTest
{
public:
	//插入类排序
	void InsertSort(int* pData, int n);
	void ShellSort(int* pData, int n);
	//交换类排序
	void BubbleSort(int* pData, int n);
	void QuickSort(int* pData, int n);
	void QuickSort2(int* pData, int n);
	//选择类排序
	void SimpleSelectionSort(int* pData, int n);
	void HeapSort(int* pData, int n);
	//归并排序，易懂的高级排序算法
	void MergeSort(int* pData, int n);
	//基数排序
	void RadixSort(int* pData, int n);

	//其它的一些排序
	//桶排序
	void BucketSort(int* pData, int n);
	//计数排序
	void CountSort(int* pData, int n);

	void testSort(void);
private:
	void Swap(int& a, int& b);
	//////////////////////////////////
	void QSort( int* pData, int low, int high );
	int Partition( int* pData, int low, int high );

	void QSort2( int* pData, int low, int high );

	//////////////////////////////////
	void SiftAdjust(int* pData, int low, int high);
	//////////////////////////////////
	void MSort( int* pData, int low, int high );
	void Merge( int* pData, int low, int mid, int high );
	//////////////////////////////////
	void RSort( int* pData, int n, int r, int d );
	void Distribute( int* pData, int n, int r, int i, vector<vector<int>>& list );
	void Collect( int* pData, int r,  vector<vector<int>>& list );
	
};