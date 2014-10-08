#pragma once

#include <iostream>
#include <map>
#include <vector>
#include <string>
using namespace std;

class SubSetTest
{
public:
	//Given a collection of numbers, return all possible permutations.
	//For example, [1,2,3] have the following permutations: [1,2,3], [1,3,2], [2,1,3], [2,3,1], [3,1,2], and [3,2,1].
	/**
 * Copyright: NineChapter
 * - Algorithm Course, Mock Interview, Interview Questions
 * - More details on: http://www.ninechapter.com/
 */
  vector<vector<int>> permute(const vector<int>& num);
  void permuteHelper(vector<vector<int>>& rst, vector<int>& list, const vector<int>& num);

  void testPermutate(void);

  //Given a list of numbers with duplicate number in it. Find all unique permutations.
  vector<vector<int>> permuteUnique(const vector<int>& num);
  void permuteUniqueHelper(vector<vector<int>>& rst, vector<int>& list, vector<int>& visited, const vector<int>& num);

  void testPermutateUnique(void);

  //Given a set of distinct integers, S, return all possible subsets. Note: Elements in a subset must be in non-descending order. 
  //The solution set must not contain duplicate subsets. For example, If S = [1,2,3], a solution is: [ [3], [1], [2], [1,2,3], [1,3], [2,3], [1,2], [] ] 
  vector<vector<int>> subset(const vector<int>& num);
  void subsetHelper(vector<vector<int>>& rst, vector<int>& list, const vector<int>& num, int pos);

  void testSubset(void);

  //Given a collection of integers that might contain duplicates, S, return all possible subsets. 
  //Note: Elements in a subset must be in non-descending order. The solution set must not contain duplicate subsets. 
  //For example, If S = [1,2,2], a solution is: [ [2], [1], [1,2,2], [2,2], [1,2], [] ] 
  vector<vector<int>> subsetUnique(const vector<int>& num);
  void subsetUniqueHelper(vector<vector<int>>& rst, vector<int>& list, const vector<int>& num, int pos);

  void testSubsetUnique(void);



  //frequent 
  // ��Ŀ����˼�ǣ�123��ȫ���а��ֵ�˳��Ϊ��123 132 213 231 312 321
  // �����������ĳһ�����У�����������һ�����С��磺���룺213 �����231 �����룺321 �����123
  // �㷨˼�룺�������� ���룺1 4 6 5 3 2
  // step1�����������ҵ���һ���ƻ�����(���ϸ�)��Ԫ�أ�������Ϊ4.���±�Ϊ i
  // step2: ��Ȼ��������,�ҵ���һ������4��Ԫ�أ�������5������4��5.
  // step3����i+1�����Ҷˣ����á�6 4 3 2 to 2 3 4 6
  // so,1 5 2 3 4 6 ��Ϊ����
  vector<int> next_permutation(vector<int>& num);
  void swap(vector<int>& num, int i, int j);
  void reverse(vector<int>& num, int start, int end);

  void testNextPermutation(void);


  //combination
   //combination sum
   // Given a set of candidate numbers (C) and a target number (T), find all unique combinations in C where the candidate numbers sums to T. 
   // The same repeated number may be chosen from C unlimited number of times. Note: All numbers (including target) will be positive integers. 
   // Elements in a combination (a1, a2, �� , ak) must be in non-descending order. (ie, a1 �� a2 �� �� �� ak). 
   // The solution set must not contain duplicate combinations. For example, given candidate set 2,3,6,7 and target 7, A solution set is: [7] [2, 2, 3]
  vector<vector<int>>  combinationSum(vector<int> num, int target);
  void combinationSumHelper( vector<int> num, int target, vector<int> path, int pos, vector<vector<int>>& rst );
  void testCombination( void );

  //combination sum ii
  // Given a collection of candidate numbers (C) and a target number (T), find all unique combinations in C where the candidate numbers sums to T.
  // Each number in C may only be used once in the combination. Note: All numbers (including target) will be positive integers. 
  // Elements in a combination (a1, a2, �� , ak) must be in non-descending order. (ie, a1 �� a2 �� �� �� ak). 
  // The solution set must not contain duplicate combinations. For example, given candidate set 10,1,2,7,6,1,5 and target 8, 
  // A solution set is: [1, 7] [1, 2, 5] [2, 6] [1, 1, 6]
  vector<vector<int>> combinationSum2(vector<int> num, int target);
  void combinationSumHelper2(vector<int> num, int target, vector<int> path, int pos, vector<vector<int>>& rst);


  //gray code
  vector<string> grayCode(int n);
  void testGrayCode( void );
};