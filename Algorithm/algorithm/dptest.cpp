#include "dptest.h"




 //Version 1: Bottom-Up
int DpTest::minimumTotal( vector<vector<int>> triangle )
{
	if (triangle.size() == 0) {
		return 0;
	}
	
	int n = triangle.size();
	vector<vector<int>>  sum(n, vector<int>(n,0));
	
	for (int i = 0; i < n; i++) {
		sum[n - 1][i] = triangle[n - 1][i];
	}

	for (int i = n - 2; i >= 0; i--) { 
		for (int j = 0; j <= i; j++) {
			sum[i][j] = min(sum[i + 1][j], sum[i + 1][j + 1]) + triangle[i][j];
		}
	}

	return sum[0][0];
}


//Version 2 : Memorize Search
int DpTest::minimumTotal2( vector<vector<int>> triangle )
{
	if (triangle.size() == 0) {
		return 0;
	}

	int n = triangle.size();
	vector<int>  sum(n);

	for (int i = 0; i < n; i++) {
		sum[i] = triangle[n - 1][i];
	}

	for (int i = n - 2; i >= 0; i--) { 
		for (int j = 0; j <= i; j++) {
			sum[j] = min(sum[j], sum[j + 1]) + triangle[i][j];
		}
	}

	return sum[0];
}

void DpTest::testMinSum( void )
{
	vector<vector<int>> triangle(4, vector<int>(4, 0));
	int arr[4][4] = {{2}, {3,4}, {6,5,7}, {4,1,8,3}};
	for (int i = 0; i < 4; ++i)
	{
		for (int j = 0; j <= i; ++j)
		{
			triangle[i][j] = arr[i][j];
		}
	}
	int minval = minimumTotal2( triangle );
	cout<<"min val: "<<minval<<endl;
}

int DpTest::uniquePath( int m, int n )
{
	if (m==0 || n==0)
	{
		return 0;
	}
	vector<vector<int>>  res(m, vector<int>(n,1));

	for (int i = 1; i < m; ++i)
	{
		for (int j = 1; j < n; ++j)
		{
			res[i][j] = res[i - 1][j] + res[i][j - 1];
		}
	}

	return res[m - 1][n - 1];
}

int DpTest::uniquePath2( vector<vector<int>> mat )
{
	if(mat.size() ==0 || mat[0].size() == 0)
	{
		return 0;
	}
	int m = mat.size();
	int n = mat[0].size();

	vector<vector<int>> res(m, vector<int>(n));

	for (int i = 0; i < m; ++i)
	{
		if (mat[i][0] != 1)
		{
			res[i][0] = 1;
		}
		else
		{
           break;
		}
	}
	for (int j = 0; j < n; ++j)
	{
		if (mat[0][j] != 1)
		{
			res[0][j] = 1;
		}
		else
		{
			break;
		}
	}

	for (int i = 1; i < m; ++i)
	{
		for (int j = 1; j < n; ++j)
		{
			if (mat[i][j] != 1)
			{
				res[i][j] = res[i - 1][j] + res[i][j - 1];
			}
			else
			{
				res[i][j] = 0;
			}
		}
	}
	return res[m - 1][n - 1];
}

void DpTest::testUniquePath( void )
{
	int res = uniquePath(2, 3);
	vector<vector<int>> mat(3,vector<int>(3));
	mat[1][1] = 1;

	int res1 = uniquePath2(mat);
	cout<<"solution: "<<res1<<endl;
}

int DpTest::minPathSum( vector<vector<int>> mat )
{
	if(mat.size() == 0 || mat[0].size() == 0)
	{
		return 0;
	}
	int n = mat.size();
	int m = mat[0].size();
	vector<vector<int>> res(n, vector<int>(n,0));
	res[0][0] = mat[0][0];
	for (int i = 1; i < m; ++i)
	{
		res[0][i] = res[0][i - 1] + mat[0][i];
	}
	for (int i = 1; i < n; ++i)
	{
		res[i][0] = res[i - 1][0] + mat[i][0];
	}

	for (int i = 1; i < n; ++i)
	{
		for (int j = 1; j < m; ++j)
		{
			res[i][j] = min(res[i - 1][j], res[i][j - 1]) + mat[i][j];
		}
	}
	return res[n - 1][m - 1];
}

int DpTest::climbStairs( int n )
{
	if (n <= 1)
	{
		return n;
	}
	int last = 1;
	int lastlast = 1;
	int now = 0;
	for (int i = 2; i <= n; i++)
	{
		now = last + lastlast;
		lastlast = last;
		last = now;
	}
	return now;
}

bool DpTest::canJump( int* A, int n )
{
	bool* can = new bool(n);
	can[0] = true;

	for (int i = 1; i < n; ++i)
	{
		for (int j= 0; j < i; ++j)
		{
			if(can[j] && j + A[j] >= i)
			{
				can[i] = true;
				break;
			}
		}
	}
	return can[n - 1];
}

int DpTest::longestCommonSubstring(const string &txt, const string &query){
	if(txt.empty() || query.empty()) return 0;

	int t_len = txt.length();
	int q_len = query.length();
	vector<int> tmp(t_len, 0), result(t_len, 0);
	int max_end = 0, max_len = 0;

	for(int i = 0; i < q_len; ++i){
		tmp.assign(t_len, 0);//clear every time
		for(int j = 0; j < t_len; ++j){
			if(query[i] == txt[j]){
				if(j == 1){
					tmp[j] = 0;
				}else{
					tmp[j] = result[j - 1] + 1;
				}
			}

			if(tmp[j] > max_len){
				max_len = tmp[j];
				max_end = j;
			}
		}// end for
		swap(tmp, result);
	}//end for
	//string s = txt.substr(max_end - max_len + 1, max_len); //获得子串
	return max_len;
}

 void DpTest::testLCS(void)
 {
	 string a = "abdfg";
     string b = "gabdfag";
	 cout<<LCS1(a,b)<<endl;
	 cout<<LCS2(a,b)<<endl;
 }

 //	DP 动态规划  O(m*n)   空间 O(m*n)
 void DpTest::LCS_dp(char* str1, char* str2)
 {
	 if (*str1 == '\0' || *str2 == '\0')
	 {
		 return;
	 }
	 int len1 = strlen(str1);
	 int len2 = strlen(str2);
	 vector<vector<int>> dp(len1, vector<int>(len2, 0));

	 int max_len = 0;
	 int max_idx = 0;
	 for (int i=0; i<strlen(str1); i++)
	 {
		 for (int j=0; j<strlen(str2); j++)
		 {
			 if (str1[i] == str2[j])
			 {
				 if (i && j)
					 dp[i][j] = dp[i-1][j-1] + 1;
				 if (i == 0 || j == 0)
					 dp[i][j] = 1;
				 if (dp[i][j] > max_len)
				 {
					 max_len = dp[i][j];
					 max_idx = i+1-dp[i][j];
				 }
			 }
		 }
	 }
	 printLCS(&str1[max_idx], max_len);
 }

 void DpTest::printLCS(char* str_com, int strlen)
 {
	 if (strlen == 0)
	 {
		 cout<<"NULL LCS"<<endl;
		 return;
	 }
	 cout<<"Common string: ";
	 for (int i=0; i<strlen; ++i)
	 {
		 cout<<str_com[i];
	 }
	 cout<<endl;
 }



 int DpTest::LCS1( string str1, string str2 )
 {
	int len1 = str1.length();
	int len2 = str2.length();

	vector<vector<int>> dp(len1, vector<int>(len2, 0));
	int maxlen = 0;
	for (int i = 0; i < len1; ++i)
	{
		for (int j = 0; j < len2; ++j)
		{
			if (str1[i] == str2[j])
			{
				if(i == 0 || j == 0)
				{
					dp[i][j] = 1;
				}
				else
				{
					dp[i][j] = dp[i - 1][j - 1] + 1;
				}
			}
			else
			{
				if(i != 0 && j != 0)
				{
					dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
				}
			}
			maxlen = max(maxlen, dp[i][j]);
		}
	}
	return maxlen;
 }

 string DpTest::LCS2( string str1, string str2 )
 {
	 int len1 = str1.length();
	 int len2 = str2.length();

	 vector<vector<int>> dp(len1, vector<int>(len2, 0));
	 int maxlen = 0;
	 int maxIndex = 0;
	 for (int i = 0; i < len1; ++i)
	 {
		 for (int j = 0; j < len2; ++j)
		 {
			 if (str1[i] == str2[j])
			 {
				 if(i == 0 || j == 0)
				 {
					 dp[i][j] = 1;
				 }
				 else
				 {
					 dp[i][j] = dp[i - 1][j - 1] + 1;
				 }
			 }
			 if (dp[i][j] > maxlen)
			 {
				 maxlen = dp[i][j];
				 maxIndex = i;
			 }
		 }
	 }
	 
	 return str1.substr(maxIndex - maxlen + 1, maxIndex + 1);
 }




