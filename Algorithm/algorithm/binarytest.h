#pragma once

#include <iostream>
#include <vector>
using namespace std;

class BinaryTest
{
public:
	// Binary search is a famous question in algorithm. For a given sorted array (ascending order) and a target number, 
	// find the first index of this number in O(log n) time complexity. If the target number does not exist in the array, 
	// return -1. Example If the array is [1, 2, 3, 3, 4, 5, 10], for given target 3, return 2.
	int binarySearch( vector<int> data, int target );

	void testBinarySearch( void );
	// Given a sorted array and a target value, return the index if the target is found. If not, return the index where 
	// it would be if it were inserted in order. You may assume no duplicates in the array. Here are few examples. 
	// [1,3,5,6], 5 ¡ú 2 [1,3,5,6], 2 ¡ú 1 [1,3,5,6], 7 ¡ú 4 [1,3,5,6], 0 ¡ú 0 
	int searchInsert( vector<int> data, int target);

	void testSearchInsert( void );

	// Given a sorted array of integers, find the starting and ending position of a given target value. 
	// Your algorithm's runtime complexity must be in the order of O(log n). If the target is not found in the array, 
	// return [-1, -1]. For example, Given [5, 7, 7, 8, 8, 10] and target value 8, return [3, 4].
	int* rangeSearch( vector<int> data, int target );

	int rangeSearchHelper( vector<int> data, int target, int mode);

	void testRangeSearch( void );
	
	// Suppose a sorted array is rotated at some pivot unknown to you beforehand. 
	// (i.e., 0 1 2 4 5 6 7 might become 4 5 6 7 0 1 2). You are given a target value to search. 
	// If found in the array return its index, otherwise return -1. You may assume no duplicate exists in the array. 
	int rotateSearch( vector<int> data, int target );

	void testRotateSearch( void );

	// Write an efficient algorithm that searches for a value in an m x n matrix. 
	// This matrix has the following properties: Integers in each row are sorted from left to right. 
	// The first integer of each row is greater than the last integer of the previous row. For example, 
	// Consider the following matrix: [ [1, 3, 5, 7], [10, 11, 16, 20], [23, 30, 34, 50] ] Given target = 3, return true. 
	bool searchMatrix( vector<vector<int>> matrix, int target );
	void testSearchMatrix( void );


	///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	
	// Given a sorted array, remove the duplicates in place such that each element appear only once and return the new length. 
	// Do not allocate extra space for another array, you must do this in place with constant memory. 
	// For example, Given input array A = [1,1,2], Your function should return length = 2, and A is now [1,2]. 
	int removeDuplicates(int A[], int n);
	void testRemoveDuplicates( void );

	// Given two sorted integer arrays A and B, merge B into A as one sorted array. 
    // Note: You may assume that A has enough space (size that is greater or equal to m + n) to hold additional elements from B. 
	// The number of elements initialized in A and B are m and n respectively. 
	void mergeSortedArray(int A[], int n, int B[], int m);
	void testMergeSortedArray( void );

	// There are two sorted arrays A and B of size m and n respectively. Find the median of the two sorted arrays. 
	// The overall run time complexity should be O(log (m+n)).
	float findMedianSortedArrays(int A[], int n, int B[], int m);
	int findKth( int A[], int Astart, int n, int B[], int Bstart, int m, int k );
	void testFindMedianSortedArrays( void );

	// Given a rotated sorted array, recover it to sorted array in-place. Example [4, 5, 1, 2, 3] -> [1, 2, 3, 4, 5]
	void reverse(vector<int>& A, int start, int end);
	void recoverRotatedSortedArray(vector<int>& A);

	void testRecoverRotatedSortedArray( void );

	int findPeek(int A[], int n);
	void testFindPeek(void);
};