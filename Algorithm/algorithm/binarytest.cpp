#include "binarytest.h"

#include <limits>

int BinaryTest::binarySearch( vector<int> data, int target )
{
	if (data.size() == 0)
	{
		return -1;
	}

	int start = 0;
	int end = data.size() - 1;
	int mid;
	while (start + 1 < end)
	{
		mid = start + (end - start) / 2;
		if (data[mid] == target)
		{
			return mid;
		}
		else if (data[mid] > target)
		{
			end = mid;
		}
		else
		{
			start = mid;
		}
	}

	if (data[start] == target)
	{
		return start;
	}
	if (data[end] == target)
	{
		return end;
	}
	return -1;
}

void BinaryTest::testBinarySearch( void )
{
	vector<int> searchArr;
	int iniArr[] = {3, 5, 9, 12, 17, 21, 33};
	searchArr.insert(searchArr.begin(), iniArr, iniArr + sizeof(iniArr) / sizeof(int));
    int index = binarySearch(searchArr, 9);
	cout<<"Index is: "<<index<<endl;
}

int BinaryTest::searchInsert( vector<int> data, int target )
{
	if (data.size() == 0)
	{
		return 0;            //attention
	}
	int start = 0;
	int end = data.size() - 1;
	int mid;
    while ( start + 1 < end)
    {
		mid = start + (end - start) / 2;
		if (data[mid] == target)
		{
			return mid;
		}
		else if(data[mid] > target)
		{
			end = mid;
		}
		else
		{
			start = mid;
		}
    }
	if (data[start] == target)
	{
		return start;
	}
	if (data[end] == target)
	{
		return end;
	}
	if (data[end] < target)
	{
		return end + 1;
	}
	return start;   //attention: don't forget
}

void BinaryTest::testSearchInsert( void )
{
	vector<int> searchArr;
	int iniArr[] = {3, 5, 9, 12, 17, 21, 33};
	searchArr.insert(searchArr.begin(), iniArr, iniArr + sizeof(iniArr) / sizeof(int));
	int index = searchInsert(searchArr, 33);
	cout<<"Index is: "<<index<<endl;
}

int* BinaryTest::rangeSearch( vector<int> data, int target )
{
	int* res = new int[2];
	if (data.size() == 0)
	{
		res[0] = -1;
		res[1] = -1;
		return res;
	}
	res[0] = rangeSearchHelper( data, target, 0 );
	res[1] = rangeSearchHelper( data, target, 1 );

	return res;	
}

int BinaryTest::rangeSearchHelper( vector<int> data, int target, int mode )
{
	int start = 0;
	int end = data.size() - 1;
	int mid;

	while (start + 1 < end)
	{
		mid = start + (end - start) / 2;
		if(data[mid] == target)
		{
			if (mode == 0)
			{
				end = mid;
			}
			else
			{
				start = mid;
			}
			
		}
		else if(data[mid] > target)
		{
			end = mid;
		}
		else
		{
			start = mid;
		}
	}
	if (mode == 0)
	{
		if (data[start] == target)
		{
			return start;
		}
		if (data[end] == target)
		{
			return end;
		}
	}
	else
	{
		if (data[end] == target)
		{
			return end;
		}
		if (data[start] == target)
		{
			return start;
		}
	}
	return -1;
}


void BinaryTest::testRangeSearch( void )
{
	vector<int> searchArr;
	//int iniArr[] = {5, 7, 7, 8, 8, 10};
	int iniArr[] = {8, 8, 8, 8, 8, 8};
	searchArr.insert(searchArr.begin(), iniArr, iniArr + sizeof(iniArr) / sizeof(int));
	int* rangeIndex = rangeSearch(searchArr, 8);
	cout<<"Index is: "<<rangeIndex[0]<<" ,"<<rangeIndex[1]<<endl;
}

int BinaryTest::rotateSearch( vector<int> data, int target )
{
	if (data.size() == 0)
	{
		return -1;
	}
	int start = 0;
	int end = data.size() - 1;
	int mid;
	while (start + 1 < end)
	{
		mid = start + (end - start) / 2;
		if (data[mid] == target)
		{
			return mid;
		}
		else if (data[mid] > data[end])
		{
			if (data[start] <= target && target <= data[mid])
			{
				end = mid;
			}
			else
			{
				start = mid;
			}
		}
		else
		{
			if (data[end] >= target && target >= data[mid])
			{
				start = mid;
			}
			else
			{
				end = mid;
			}
		}
	}
	if (data[start] == target)
	{
		return start;
	}
	if (data[end] == target)
	{
		return end;
	}
	return -1;
}

void BinaryTest::testRotateSearch( void )
{
	vector<int> searchArr;
	int iniArr[] = {4, 5, 6, 7, 0, 1, 2};
	searchArr.insert(searchArr.begin(), iniArr, iniArr + sizeof(iniArr) / sizeof(int));
	int index = rotateSearch(searchArr, 6);
	cout<<"Index is: "<<index<<endl;
}

bool BinaryTest::searchMatrix( vector<vector<int>> matrix, int target )
{
	if (matrix.size() == 0)
	{
		return false;
	}
	int cols = matrix[0].size();
	int rows = matrix.size();

	int start = 0;
	int end = cols * rows - 1;
	int mid;
	while (start + 1 < end)
	{
		mid = start + (end - start) / 2;
		int midVal = matrix[mid / cols][mid % cols];
		if (midVal == target)
		{
			return true;
		}
		else if(midVal < target)
		{
			start = mid;
		}
		else
		{
			end = mid;
		}
	}
	if (matrix[end / cols][end % cols] == target)
	{
		return true;
	}
	if (matrix[start / cols][start % cols] == target)
	{
		return true;
	}
	return false;
}

void BinaryTest::testSearchMatrix( void )
{
	vector<vector<int>> testM;
	int iniM[][4] = { {1, 3, 5, 7}, {10, 11, 16, 20}, {23, 30, 34, 50} };
	for (int i = 0; i < 3; i++)
	{
		vector<int> row;
		for (int j = 0; j < 4; j++)
		{
			row.push_back(iniM[i][j]);
		}
		testM.push_back(row);
	}
 
    cout<<"exist: "<<searchMatrix(testM, 5)<<endl;
}

int BinaryTest::removeDuplicates( int A[], int n )
{
	if (n == 0 || A == NULL)
	{
		return 0;
	}
	int count = 0;
	for (int i = 0; i < n; ++i)
	{
		if (A[i] != A[count])
		{
			A[++count] = A[i];
		}
	}
	return count + 1;
}

void BinaryTest::testRemoveDuplicates( void )
{
	int A[] = {1, 1, 2, 3, 4, 4}; 
	cout<<"num: "<<removeDuplicates(A, 6)<<endl;
}

void BinaryTest::mergeSortedArray( int A[], int n, int B[], int m )
{
	int i = n - 1;
	int j = m - 1;
	int count = m + n -1;
	while (i >= 0 && j >= 0)    //attention:  >=  not >
	{
		if (A[i] < B[j])
		{
			A[count--] = B[j--];   //attention: count--
		}
		else
		{
			A[count--] = A[i--];
		}
	}
	while (j >= 0)     //attention:  >=  not >
	{
		A[count--] = B[j--];
	}
}

void BinaryTest::testMergeSortedArray( void )
{
	int A[11] = {2, 5, 9, 15, 32};
	int B[] = {1, 3, 18, 21, 31, 55};
	mergeSortedArray(A, 5, B, 6);
	for (int i = 0; i < 11; ++i)
	{
		cout<<A[i]<<", ";
	}
	cout<<endl;
}

float BinaryTest::findMedianSortedArrays( int A[], int n, int B[], int m )
{
	float midVal;
	if ( (n + m) % 2 == 0)
	{
		midVal = (findKth(A, 0, n, B, 0, m, (n + m) / 2 ) + findKth(A, 0, n, B, 0, m,(n + m) / 2 + 1)) / 2.0;    //attention: 2.0  not 2
	}
	else
	{
		midVal = findKth(A, 0, n, B, 0, m, (n + m) / 2 + 1);
	}
	return midVal;
}

int BinaryTest::findKth( int A[], int Astart, int n, int B[], int Bstart, int m, int k )
{
	if (Astart >= n)
	{
		return B[Bstart + k - 1];
	}
	if (Bstart >= m)
	{
		return A[Astart + k - 1];
	}

	if (k == 1)
	{
		return min(A[Astart], B[Bstart]);
	}

	int Akey = (Astart + k / 2 - 1) < n ? A[Astart + k / 2 - 1] : INT_MAX;
	int Bkey = (Bstart + k / 2 - 1) < m ? B[Bstart + k / 2 - 1] : INT_MAX;

	if (Akey < Bkey)
	{
		return findKth(A, Astart + k / 2, n, B, Bstart, m, k - k / 2);     //attention: add return
	}
	else
	{
		return findKth(A, Astart, n, B, Bstart + k / 2, m, k - k / 2);
	}
	
}

void BinaryTest::testFindMedianSortedArrays( void )
{
	int A[11] = {2, 5, 9, 15, 32, 88};
	int B[] = {1, 3, 18, 21, 31, 55};
	cout<<"median: "<<findMedianSortedArrays(A, 6, B, 6)<<endl;
}

void BinaryTest::reverse( vector<int>& A, int start, int end )
{
	for (int i = start, j = end; i < j; ++i, --j)                   //attention:  i < j not i < A.size() / 2
	{
		int tmp = A[i];
		A[i] = A[j];
		A[j] = tmp;
	}
}

void BinaryTest::recoverRotatedSortedArray( vector<int>& A )
{
	for (int i = 0; i < A.size() - 1; ++i)
	{
		if (A[i] > A[i + 1])
		{
			reverse(A, 0, i);
			reverse(A, i + 1, A.size() - 1);
			reverse(A, 0, A.size() - 1);
			return;
		}
	}
}

void BinaryTest::testRecoverRotatedSortedArray( void )
{
	int iniArr[5] = {4, 5, 1, 2, 3};
    vector<int> testArr;
	testArr.insert(testArr.begin(), iniArr, iniArr + 5);
	recoverRotatedSortedArray(testArr);
	for (int i = 0; i < testArr.size(); ++i)
	{
		cout<<testArr[i]<<" ";
	}
	cout<<endl;
}

int BinaryTest::findPeek( int A[], int n )
{
	if(A == NULL || n < 3)
	{
      return -1;
	}

	int start = 0;
	int end = n - 1;
	int mid;

	while(start + 1 < end)
	{
		mid = start + (end - start) / 2;
	    if(A[mid] < A[mid + 1])
		{
			start = mid;
		}
		else
		{
			end = mid;
		}
	}

	if ((start > 0 )&& ( A[start] > A[start - 1] )&& (A[start] > A[start + 1]))
	{
		return start;
	}
	if ((end < (n - 1)) && (A[end] > A[end - 1]) && (A[end] > A[end + 1]))
	{
		return end;
	}
	return -1;
}

void BinaryTest::testFindPeek( void ) 
{
	int arr[9] = {1, 2, 8, 4, 5, 6, 5, 7, 2};
    int peek = findPeek(arr, sizeof(arr) / sizeof(int));
	if(peek != -1)
		cout<<arr[peek]<<endl;
	else
		cout<<-1<<endl;
}
