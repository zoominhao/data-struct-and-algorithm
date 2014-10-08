#pragma once

#include <iostream>
#include <vector>
using namespace std;

class SortTest
{
public:
	//����������
	void InsertSort(int* pData, int n);
	void ShellSort(int* pData, int n);
	//����������
	void BubbleSort(int* pData, int n);
	void QuickSort(int* pData, int n);
	void QuickSort2(int* pData, int n);
	//ѡ��������
	void SimpleSelectionSort(int* pData, int n);
	void HeapSort(int* pData, int n);
	//�鲢�����׶��ĸ߼������㷨
	void MergeSort(int* pData, int n);
	//��������
	void RadixSort(int* pData, int n);

	//������һЩ����
	//Ͱ����
	void BucketSort(int* pData, int n);
	//��������
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