#include "sorttest.h"

void SortTest::InsertSort( int* pData, int n )
{
	for (int i = 1; i < n; ++i)
	{
		for (int j = i; j > 0; j--)
		{
			if (pData[j - 1] > pData[j])
			{
				Swap(pData[j - 1], pData[j]);
			}
			else
			{
				break;
			}
		}
	}
}

void SortTest::ShellSort( int* pData, int n )
{
	int incr = n;
	while (incr > 1)
	{
		incr = incr / 3 +1;
		for (int i = incr; i < n; ++i)
		{
			for (int j = i; j > incr -1; j -= incr)
			{
				if (pData[j - incr] > pData[j])
				{
					Swap(pData[j - incr], pData[j]);
				}
				else
				{
					break;
				}
			}
		}
	}
}

void SortTest::BubbleSort( int* pData, int n )
{
	int lastSwapPos = n - 1;

	for (int i = n - 1; i > 0; i = lastSwapPos)
	{
		lastSwapPos = 0;                  //attention, set lastSwapPos = 0
		for (int j = 0; j < i; ++j)
		{
			if (pData[j + 1] < pData[j])
			{
				Swap(pData[j + 1], pData[j]);
				lastSwapPos = j;
			}
		}
	}
}


void SortTest::QuickSort( int* pData, int n )
{
	QSort(pData, 0, n-1);
}

void SortTest::QSort( int* pData, int low, int high )
{
	if (low < high)
	{
		int pivot = Partition(pData, low, high);
		QSort(pData, low, pivot - 1);
		QSort(pData, pivot + 1, high);
	}
}

int SortTest::Partition( int* pData, int low, int high )
{
	while (low < high)
	{
		while (low < high && pData[high] >= pData[low])
		{
			high--;
		}
		Swap(pData[high], pData[low]);
		while (low < high && pData[low] <= pData[high])
		{
			low++;
		}
		Swap(pData[high], pData[low]);
	}
	return low;
}

void SortTest::SimpleSelectionSort( int* pData, int n )
{
	int lowIndex;
	for (int i = 0; i < n - 1; ++i)
	{
		lowIndex = i;
		for (int j = i + 1; j < n; ++j)
		{
			if ( pData[j] < pData[lowIndex] )    //attention
			{
				lowIndex = j;
			}
		}
		Swap(pData[i], pData[lowIndex]);
	}
}

void SortTest::HeapSort( int* pData, int n )
{
	//build heap
	for (int i = (n - 2)/2; i >= 0; i--)
	{
		SiftAdjust(pData, i, n - 1);
	}
	//sort
	for (int i = n - 1; i > 0 ; i--)
	{
		Swap(pData[i], pData[0]);  //swap heap top
		SiftAdjust(pData, 0, i - 1);   //adjust    //attention, not i
	}
}

void SortTest::SiftAdjust( int* pData, int low, int high )
{
	for (int f = low, i = low * 2 + 1; i <= high; i = i*2 + 1)
	{
		if (i < high && pData[i + 1] > pData[i])
		{
			i++;
		}   //right child is greater than left child
		if (pData[f] < pData[i])
		{
			Swap(pData[f], pData[i]);
		}
		else
		{
			break;
		}
		f = i;
	}
}

void SortTest::MergeSort( int* pData, int n )
{
	MSort(pData, 0, n-1);
}

void SortTest::MSort( int* pData, int low, int high )
{
	int mid;
	if (low < high)
	{
		mid = low + (high - low) / 2;
		MSort(pData, low, mid);
		MSort(pData, mid + 1, high);
		Merge(pData, low, mid, high);
	}
}

void SortTest::Merge( int* pData, int low, int mid, int high )
{
	int* tmpArr = new int[high + 1];
	int i, j, k;
	for (i = low, j = mid + 1, k = low; i <= mid && j <= high; k++)   //attention: k = low, not k =0
	{
		if (pData[i] <= pData[j])
		{
			tmpArr[k] = pData[i];
			i++;
		}
		else
		{
			tmpArr[k] = pData[j];
			j++;
		}
	}
	for (; i <= mid; ++i)
	{
		tmpArr[k++] = pData[i];
	}
	for (; j <= high; ++j)
	{
		tmpArr[k++] = pData[j];
	}
	//
	for (int i = low; i <= high; ++i)
	{
		pData[i] = tmpArr[i];
	}
	delete []tmpArr;
}

struct Barrel
{
	int node[10];
	int count;
};

void SortTest::BucketSort( int* pData, int n )
{
	int max = pData[0];
	int min = pData[0];
	for (int i = 1; i < n; ++i)
	{
		if (pData[i] > max)
		{
			max = pData[i];
		}
		if (pData[i] < min)
		{
			min = pData[i];
		}
	}
	int num = (max - min + 1) / 10 + 1;

	Barrel* pbarrels = (Barrel*)malloc(sizeof(Barrel)*num);
	memset(pbarrels, 0, sizeof(Barrel)*num);

	for (int i = 0; i < n; ++i)
	{
		int k = (pData[i] - min + 1) / 10;
		pbarrels[k].node[pbarrels[k].count] = pData[i];
		pbarrels[k].count++;
	}

	int pos = 0;
	for (int i = 0; i < num; ++i)
	{
		QSort(pbarrels[i].node, 0, pbarrels[i].count - 1);
		for (int j = 0; j < pbarrels[i].count; ++j)
		{
			pData[pos++] = pbarrels[i].node[j];
		}
	}
	free(pbarrels);    //attention: free not delete
}

void SortTest::CountSort( int* pData, int n )
{
	int max = pData[0];
	int min = pData[0];
	for (int i = 1; i < n; ++i)
	{
		if (pData[i] > max)
		{
			max = pData[i];
		}
		if (pData[i] < min)
		{
			min = pData[i];
		}
	}

	int countSize = max - min + 1;

	int* countArr = new int[countSize];

	for (int i = 0; i < countSize; ++i)
	{
		countArr[i] = 0;
	}
	for (int i = 0; i < n; ++i)
	{
		countArr[pData[i] - min]++;
	}
	for (int i = 1; i < countSize; ++i)
	{
		countArr[i] += countArr[i - 1];
	}

	int* tmpData = new int[n];

	int value, pos; 
	for (int i = 0; i < n; ++i)    //attention
	//for(int i = n-1; i >= 0; i--)
	{
		value = pData[i];
		pos = countArr[value - min];
		tmpData[pos - 1] = value;
		countArr[value - min]--;
	}
	for (int i = 0; i < n; ++i)    //attention
	{
		pData[i] = tmpData[i];
	}


	delete []countArr;
	delete []tmpData;
}

void SortTest::RadixSort( int* pData, int n )
{
	//detect 10 base
	int max = pData[0];
	int min = pData[0];
	//r base, d digit
	for (int i = 1; i < n; i++)
	{
		if( pData[i] > max)
		{
			max = pData[i];
		}
		if ( pData[i] < min )
		{
			min = pData[i];
		}
	}
	int r = 10;  //base
	int d = 0;

	while ( max > 0)
	{
		d++;
		max /= 10;
	}

	RSort(pData, n, r, d);
}

void SortTest::RSort( int* pData, int n, int r, int d )
{
	vector<vector<int>> linkList;
	for (int i = 0; i < r; ++i)
	{
		vector<int> list;
		linkList.push_back(list);
	}
	for (int i = 0; i < d; ++i)
	{
		Distribute(pData, n, r, i, linkList);
		Collect(pData, r, linkList);
	}
}

void SortTest::Distribute( int* pData, int n, int r, int i, vector<vector<int>>& list )
{
	int power = (int)pow(r, i);
	for (int k = 0; k < n; ++k)
	{
		int index = (pData[k] / power) % r;
		list[index].push_back(pData[k]);
	}
}

void SortTest::Collect( int* pData, int r, vector<vector<int>>& list )
{
	for (int i = 0, k = 0; i < r; ++i)
	{

		while (!list[i].empty())
		{
			pData[k++] = list[i][0];              //attention: k++
			list[i].erase(list[i].begin());        //attention: not   list[i].pop_back();
		}
	}
}


void SortTest::Swap( int& a, int& b )
{
	int c = a;
	a = b;
	b = c;
}

void SortTest::testSort( void )
{
	int a[] = {30,6,2,9,12,5,7};
	//RadixSort(a,7);
	CountSort(a, 7);
	for (int i = 0; i < sizeof(a)/sizeof(int); ++i)
	{
		cout<<a[i]<<" ";
	}
	cout<<endl;

}














