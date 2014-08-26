#pragma once

#include <iostream>
#include <map>
#include <vector>
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

};