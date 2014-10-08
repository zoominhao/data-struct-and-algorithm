#include "subsettest.h"

#include <algorithm>


vector<vector<int>> SubSetTest::permute( const vector<int>& num )
{
	vector<vector<int>> rst;
	if (num.size() == 0)
	{
		return rst;
	}

	vector<int> list;
	permuteHelper(rst, list, num);

	return rst;
}

void SubSetTest::permuteHelper( vector<vector<int>>& rst, vector<int>& list, const vector<int>& num )
{
	if (list.size() == num.size())
	{
		rst.push_back(list);
		return;
	}
	for (int i = 0; i < num.size(); ++i)
	{
		if (find(list.begin(), list.end(), num[i]) != list.end())
		{
			continue;
		}
		list.push_back(num[i]);
		permuteHelper(rst, list, num);
		list.pop_back();
	}
}

void SubSetTest::testPermutate( void )
{
	vector<int> testVec;
	for (int i = 1; i <= 3; ++i)
	{
		testVec.push_back(i);
	}
	vector<vector<int>> rst = permute( testVec );
	for (int i = 0; i < rst.size(); ++i)
	{
		for (int j = 0; j < rst[i].size(); ++j)
		{
			cout<<rst[i][j]<<" ";
		}
		cout<<endl;
	}

}

vector<vector<int>> SubSetTest::permuteUnique( const vector<int>& num )
{
    vector<vector<int>>  rst;
	if (num.size() == 0)
	{
		return rst;
	}
	
	vector<int> list;
	vector<int> visited;
	visited.insert(visited.begin(), num.size(), 0);
	vector<int> tmpNum = num;             //attention: const can't be modified
	sort(tmpNum.begin(),tmpNum.end(),less<int>());      //attention: ascending  greater<int>()  descending  

	permuteUniqueHelper(rst, list, visited, num);

	return rst;
}

void SubSetTest::permuteUniqueHelper( vector<vector<int>>& rst, vector<int>& list, vector<int>& visited, const vector<int>& num )
{
	if (list.size() == num.size())
	{
		rst.push_back(list);
		return;    //attention
	}
	for (int i = 0; i < num.size(); ++i)
	{
		if (visited[i] == 1 || (i != 0 && num[i] == num[i - 1] && visited[i - 1] == 0)){
			continue;
		}
		
		visited[i] = 1;
		list.push_back(num[i]);
		permuteUniqueHelper(rst, list, visited, num);
		list.pop_back();
		visited[i] = 0;  //visited[visited.size() - 1] = 0;  //attention: wrong
	}
}

void SubSetTest::testPermutateUnique( void )
{
	vector<int> testVec;
	int myarray[] = { 1, 2, 2 };
	testVec.insert (testVec.begin(), myarray, myarray+3);

	vector<vector<int>> rst = permuteUnique( testVec );
	for (int i = 0; i < rst.size(); ++i)
	{
		for (int j = 0; j < rst[i].size(); ++j)
		{
			cout<<rst[i][j]<<" ";
		}
		cout<<endl;
	}
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////

vector<vector<int>> SubSetTest::subset( const vector<int>& num )
{
	vector<vector<int>> rst;
	if (num.size() == 0)
	{
		return rst;
	}

	vector<int> list;
	vector<int> tmpNum = num;
	//sort(tmpNum.begin(), tmpNum.end(), less<int>());

	subsetHelper(rst, list, tmpNum, 0);

	return rst;
}

void SubSetTest::subsetHelper( vector<vector<int>>& rst, vector<int>& list, const vector<int>& num, int pos )
{
	rst.push_back(list);

	for (int i = pos; i < num.size(); ++i)
	{
		list.push_back(num[i]);
		subsetHelper(rst, list, num, i + 1);
		list.pop_back();
	}
}

void SubSetTest::testSubset( void )
{
	vector<int> testVec;
	int a[] = {1, 2, 3};
	testVec.insert(testVec.begin(), a, a + 3);

	vector<vector<int>> rst = subset( testVec );
	for (int i = 0; i < rst.size(); ++i)
	{
		for (int j = 0; j < rst[i].size(); ++j)
		{
			cout<<rst[i][j]<<" ";
		}
		cout<<endl;
	}
}

vector<vector<int>> SubSetTest::subsetUnique( const vector<int>& num )
{
	vector<vector<int>> rst;
	if (num.size() == 0)
	{
		return rst;
	}
	vector<int> list;
	vector<int> tmpNum = num;
	sort(tmpNum.begin(), tmpNum.end(), less<int>());

	subsetUniqueHelper(rst, list, num, 0);

	return rst;
}

void SubSetTest::subsetUniqueHelper( vector<vector<int>>& rst, vector<int>& list, const vector<int>& num, int pos )
{
	rst.push_back(list);
	for (int i = pos; i < num.size(); ++i)
	{
		if (i != pos && num[i - 1] == num[i])
		{
			continue;
		}
		list.push_back(num[i]);
		subsetUniqueHelper(rst, list, num, i + 1);
		list.pop_back();
	}
}

void SubSetTest::testSubsetUnique( void )
{
	vector<int> testVec;
	int a[] = {1, 2, 2};
	testVec.insert(testVec.begin(), a, a + 3);

	vector<vector<int>> rst = subsetUnique( testVec );
	for (int i = 0; i < rst.size(); ++i)
	{
		for (int j = 0; j < rst[i].size(); ++j)
		{
			cout<<rst[i][j]<<" ";
		}
		cout<<endl;
	}
}

vector<int> SubSetTest::next_permutation( vector<int>& num )
{
	if (num.size() == 0)
	{
		return num;
	}
	int len = num.size();
	for (int i = len - 2; i >= 0; --i)
	{
		if (num[i] < num[i + 1])
		{
		  int j;
		  for (j = len - 1; j > i - 1; --j)
		  {
			  if(num[j] > num[i])
			  {
				  break;
			  }
		  }
		  swap(num, i, j);
		  reverse(num, i + 1, len - 1);
		  return num;
		}
	}
   reverse(num, 0, len - 1);
   return num;
}

void SubSetTest::swap( vector<int>& num, int i, int j )
{
	int tmp = num[i];
	num[i] = num[j];
	num[j] = tmp;
}

void SubSetTest::reverse( vector<int>& num, int start, int end )
{
	while (start < end)
	{
		swap(num, start++, end--);
	}
}

void SubSetTest::testNextPermutation( void )
{
	int arr[] = {1, 4, 6, 5, 3, 2};   //1 5 2 3 4 6
	vector<int> vec;
	vec.insert(vec.begin(), arr, arr + sizeof(arr) / sizeof(int));
	next_permutation(vec);
	for (int i = 0; i < vec.size(); ++i)
	{
		cout<<vec[i]<<" ";
	}
	cout<<endl;
}

vector<vector<int>> SubSetTest::combinationSum( vector<int> num, int target )
{
	vector<vector<int>> rst;
	if (num.size() == 0)
	{
		return rst;
	}
	vector<int> path;
    sort(num.begin(), num.end(), less<int>());
	combinationSumHelper(num, target, path, 0, rst);
	return rst;
}

void SubSetTest::combinationSumHelper( vector<int> num, int target, vector<int> path, int pos, vector<vector<int>>& rst )
{
	if (target == 0)
	{
		rst.push_back(path);
		return;
	}
	int prev = -1;
	for (int i = pos; i < num.size(); i++) {
		if (num[i] > target) {
			break;
		}

		if (prev != -1 && prev == num[i]) {
			continue;
		}

		path.push_back(num[i]);
		combinationSumHelper(num, target - num[i], path, i, rst);
		path.pop_back();

		prev = num[i];
	}
}

vector<vector<int>> SubSetTest::combinationSum2( vector<int> num, int target )
{
	vector<vector<int>> rst;
	if (num.size() == 0)
	{
		return rst;
	}
	vector<int> path;
	sort(num.begin(), num.end(), less<int>());
	combinationSumHelper2(num, target, path, 0, rst);
	return rst;
}

void SubSetTest::combinationSumHelper2( vector<int> num, int target, vector<int> path, int pos, vector<vector<int>>& rst )
{
	if (target == 0)
	{
		rst.push_back(path);
		return;
	}
	int prev = -1;
	for (int i = pos; i < num.size(); ++i)
	{
		if (num[i] > target)
		{
			break;
		}
		if(prev == num[i])
		{
			continue;
		}
		path.push_back(num[i]);
		combinationSumHelper2( num, target - num[i], path, i + 1, rst );
		path.pop_back();
		prev = num[i];
	}
}


void SubSetTest::testCombination( void )
{
	int arr[] = {1, 4, 6, 5, 3, 2};   //1 5 2 3 4 6
	vector<int> vec;
	vec.insert(vec.begin(), arr, arr + sizeof(arr) / sizeof(int));
	vector<vector<int>> rst = combinationSum2(vec, 5);
	for (int i = 0; i < rst.size(); ++i)
	{
		for (int j = 0; j < rst[i].size(); ++j)
		{
			cout<<rst[i][j]<<" ";
		}
		cout<<endl;
	}

}

vector<string> SubSetTest::grayCode( int n )
{
	vector<string> code;
	code.resize(pow(2, n));

	if(n == 1){
		code[0] = "0";
		code[1] = "1";
		return code;
	}

	vector<string> last = grayCode(n - 1);
	for(int i = 0; i < last.size(); ++i){
		code[i] = "0" + last[i];
		code[code.size() - 1 - i] = last[i] + "1";
	}
	return code;
}

void SubSetTest::testGrayCode( void )
{
	vector<string> res = grayCode(3);
	for (int i = 0; i < res.size(); ++i)
	{
		cout<<res[i]<<" ";
	}
	cout<<endl;
}

