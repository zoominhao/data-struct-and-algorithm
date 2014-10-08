#pragma once

#include <iostream>
#include <vector>
#include <string>

using namespace std;

class DpTest
{
public:
	// Given a triangle, find the minimum path sum from top to bottom. 
	// Each step you may move to adjacent numbers on the row below. 
	// For example, given the following triangle [ [2], [3,4], [6,5,7], [4,1,8,3] ] 
	// The minimum path sum from top to bottom is 11 (i.e., 2 + 3 + 5 + 1 = 11). 
    // Note: Bonus point if you are able to do this using only O(n) extra space, where n is the total number of rows in the triangle.
   int minimumTotal(vector<vector<int>> triangle);
   //O(n)
   int minimumTotal2(vector<vector<int>> triangle);

   void testMinSum( void );


   // Unique Path
   int uniquePath(int m, int n);
   // Unique Path ii : obstacle
   int uniquePath2(vector<vector<int>> mat);
   void testUniquePath( void );

   //Minimum Path Sum
   int minPathSum(vector<vector<int>> mat);

   //climbing stairs
   // You are climbing a stair case. It takes n steps to reach to the top. 
   // Each time you can either climb 1 or 2 steps.
   // In how many distinct ways can you climb to the top? 
   int climbStairs(int n);

   //jump game
   // Given an array of non-negative integers, you are initially positioned at the first index of the array. 
   // Each element in the array represents your maximum jump length at that position.
   // Determine if you are able to reach the last index. For example: A = [2,3,1,1,4], return true. A = [3,2,1,0,4], return false. 
   bool canJump(int* A, int n);

   int longestCommonSubstring(const string &txt, const string &query);

   void LCS_dp(char* str1, char* str2);
   void printLCS(char* str_com, int strlen);

   void testLCS(void);

   int LCS1(string str1, string str2);
   string LCS2(string str1, string str2);

};