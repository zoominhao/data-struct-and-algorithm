#include "simpletest.h"



int SimpleTest::getAbsDays( Date date )
{
	//set 0001.01.01
	int month_day[] = {31,28,31,30,31,30,31,31,30,31,30,31};
	int year = date.year - 1;
	int days = year * 365 + year / 4 - year / 100 + year / 400;
	if (date.year % 4 == 0 && date.year % 100 != 0 || date.year % 400 == 0)
	{
		month_day[1] += 1;
	}
	for (int i = 0; i < date.month - 1; ++i)
	{
		days += month_day[i];
	}
	days += date.day - 1;

	return days;
}

int SimpleTest::getDateDiff( Date date1, Date date2 )
{
	return abs(getAbsDays(date2) - getAbsDays(date1));
}

void SimpleTest::testDaysDiff( void )
{
	Date datea = {1998,3,18}; 
	Date dateb = {2000,3,18}; 

	int n = getDateDiff(datea, dateb); 
	cout<<"diff days:"<<n<<endl;
}

int SimpleTest::gcd( int num1, int num2 )
{
	int a = max(num1, num2);
	int b = min(num1, num2);
	int tmp;
	while (b != 0)
	{
		tmp = a % b;
		a = b;
		b = tmp;
	}
	return a;
}

void SimpleTest::testGcd( void )
{
	cout<<gcd(8,6)<<endl;
}

double SimpleTest::mySqrt( double num )
{
	double n = num / 2;
	double m = (n + num / n)/2;

	while(abs( n - m ) > 1e-6)
	{
		n = m;
	    m = ( n + num / n ) / 2;
	}
	return m;
}

double SimpleTest::mySqrt2( double num )
{
	double start = 0;
	double end = num;
	double mid;
	while ( abs( start - end ) > 1e-6 )
	{
		mid = start + (end - start) / 2;
	    if(abs( mid*mid - num ) < 1e-6)
		{
			return mid;
		}
		else if (mid*mid > num)
		{
			end = mid;
		}
		else
		{
			start = mid;
		}
	}
	return mid;
}

void SimpleTest::testSqrt( void )
{
	cout<<mySqrt(55)<<endl;
}

int SimpleTest::singleNumber( int A[], int n )
{
	if(A == NULL || n == 0)
	{
		return -1;
	}
	int res = A[0];
	for (int i = 1; i < n; ++i)
	{
		res ^= A[i]; 
	}
	return res;
}

int SimpleTest::singleNumber2( int A[], int n )
{
	if (A == NULL || n == 0)
	{
		return -1;
	}
	int rst = 0;
	int* bits = new int[32];
	for (int i = 0; i < 32; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			bits[i] += A[j] >> i & 1;
			bits[i] %= 3;
		}
		rst |= (bits[i] << i);
	}
	return rst;
}

int* SimpleTest::twoSingleNumber( int A[], int n )
{
	int res[2] = {-1, -1};
	if(A == NULL || n < 2)
	{
		return res;
	}

	int cur = 0;
	for (int i = 0; i < n; ++i)
	{
		cur ^= A[i];
	}

	int k=0;  
	while((cur & 1<<k)==0) ++k;  

	k = (1<<k);
	int t1 = cur, t2 = cur;
	for (int i = 0; i < n; ++i)
	{
		if((A[i] & k) == k)
		{
			t1 ^= A[i];
		}
	}
	for (int i = 0; i < n; ++i)
	{
		if((A[i] & k) == 0)
		{
			t2 ^= A[i];
		}
	}
	res[0] = t1;
	res[1] = t2;
	return res;
}

void SimpleTest::testSignleNumber( void )
{
	int arr1[] = {3, 4, 5, 4, 5};
	int arr2[] = {2, 4, 5, 4, 4, 5, 5, 3, 3, 3};
	int arr3[] = {3, 4, 5, 5, 7, 6, 6, 7};

	cout<<"1: "<<singleNumber(arr1, sizeof(arr1) / sizeof(int))<<endl;
	cout<<"2: "<<singleNumber2(arr2, sizeof(arr2) / sizeof(int))<<endl;
	int* res = twoSingleNumber(arr3, sizeof(arr3) / sizeof(int));
	cout<<"3: "<<res[0]<<" "<<res[1]<<endl;
}

int SimpleTest::majorityNumber( int A[], int n )
{
	if (A == NULL || n == 0)
	{
		return -1;
	}
	int maj;
	int count = 0;
	for (int i = 0; i < n; ++i)
	{
		if(count == 0)
			maj = A[i];
		if(maj == A[i])
		    count++;
		else
			count--;
	}
	count = 0;
	for (int i = 0; i <n; ++i)
	{
		if(A[i] == maj)
		{
			count++;
		}
	}
	if(count > n / 2)
	{
		return maj;
	}
	else
	{
		return -1;
	}
}

int SimpleTest::majorityNumber2( int A[], int n )
{
	int maj[2] = {INT_MAX, INT_MAX};
	int count[2] = {0, 0};
	for (int i = 0; i < n; ++i)
	{
		if(count[0] == 0)
		{
			maj[0] = A[i]; 
		}
		else if(count[1] == 0)
		{
			maj[1] = A[i];
		}
		if(A[i] == maj[0])
		{
			count[0]++;
		}
		else if(A[i] == maj[1])
		{
			count[1]++;
		}
		else
		{
			count[0]--;
			count[1]--;
		}
	}
	if (count[0] > count[1])
	{
		return maj[0];
	}
	else
	{
		return maj[1];
	}
	
}

int SimpleTest::majorityNumber3( int A[], int n, int k )
{
	if (A == NULL || n== 0 || k < 0)
	{
		return NULL;
	}
	int* count = new int[k];
	memset(count, 0, sizeof(int)*k);
	int* maj = new int[k];

	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < k; ++j)
		{
			if(count[j] == 0)
			{
				maj[j] = A[i];
				break;
			}
		}
		bool flag = true;
		for (int j = 0; j < k; ++j)
		{
			if (maj[j] == A[i])
			{
				count[j]++;
				flag = false;
				break;
			}
		}
		if (flag)
		{
			for (int j = 0; j < k; ++j)
			{
				count[j]--;
			}
		}
	}
	//sort
	return maj[0];

}

void SimpleTest::testMajorityNumber( void )
{
	int arr1[] = {1,1,1,1,2,2,5};
	int arr2[] = {1, 2, 1, 2, 1, 3, 3, 3, 3, 3};
	cout<<"1: "<<majorityNumber(arr1, sizeof(arr1) / sizeof(int))<<endl;
	cout<<"2: "<<majorityNumber2(arr2, sizeof(arr2) / sizeof(int))<<endl;
	//cout<<"3: "<<majorityNumber3(arr2, sizeof(arr2) / sizeof(int), 2)<<endl;
}

int SimpleTest::maxProfit( int price[], int n )
{
	if (price == NULL || n <= 1)
	{
		return 0;
	}
	int minVal = INT_MAX;
	int profit = 0;
	for (int i = 0; i < n; ++i)
	{
		minVal = min(minVal, price[i]);
		profit = max(price[i] - minVal, profit);
	}
	return profit;
}

int SimpleTest::maxProfit2( int price[], int n )
{
	if (price == NULL || n <= 1)
	{
		return 0;
	}
	int profit = 0;
	for (int i = 0; i < n - 1; ++i)
	{
		int diff = price[i + 1] - price[i];
		if(diff > 0)
		{
			profit += diff;
		}
	}
	return profit;
}

int SimpleTest::maxProfit3( int price[], int n )
{
	if (price == NULL || n <= 1)
	{
		return 0;
	}
	int* left = new int[n];
	int* right = new int[n];

	//DP from left to right
	left[0] = 0;
	int minVal = price[0];
	for (int i = 1; i < n; ++i)
	{
		minVal = min(minVal, price[i]);
		left[i] = max(price[i] - minVal, left[i - 1]);
	}

	//DP from right to left
	right[n - 1] = 0;
	int maxVal = price[n - 1];
	for (int i = n - 2; i >= 0; --i)
	{
		maxVal = max(price[i], maxVal);
		right[i] = max(maxVal - price[i], right[i + 1]);
	}

	int profit = 0;
	for (int i = 0; i < n; ++i)
	{
		// sell and buy point
		profit = max(left[i] + right[i], profit);
	}
	return profit;
}

void SimpleTest::testMaxProfit( void )
{
	int arr1[] = {1,1,1,1,2,2,5};
	cout<<"1: "<<maxProfit(arr1, sizeof(arr1) / sizeof(int))<<endl;
}

int SimpleTest::maxSubArray( int A[], int n )
{
	if(A == NULL || n == 0)
	{
		return 0;
	}

	int maxVal = INT_MIN;
	int sum = 0;
	for (int i = 0; i < n; ++i)
	{
		sum += A[i];
		maxVal = max(maxVal, sum);
		sum = max(sum, 0);
	}
	return maxVal;
}

int SimpleTest::maxTwoSubArray( int A[], int n )
{
	if (A == NULL || n < 1)
	{
		return 0;
	}

}

int SimpleTest::maxProduct( int A[], int n )
{
	if(A == NULL || n == 0)
	{
		return 0;
	}

	int maxres = A[0];
	int minProduct = A[0];
	int maxProduct = A[0];
	for (int i = 1; i < n; ++i)
	{
		if(A[i] > 0)
		{
			maxProduct = max(maxProduct * A[i], A[i]);
			minProduct = min(minProduct * A[i], A[i]);
		}
		else
		{
			int oldMax = maxProduct;
			maxProduct = max(minProduct * A[i], A[i]);
			minProduct = min(oldMax * A[i], A[i]);
		}
		maxres = max(maxres, maxProduct);
	}
	return maxres;
}

int SimpleTest::str2int( string str )
{
	int sign = 1;
	long long num = 0;

	for (int i = 0; i < str.length(); ++i)
	{
		if (i == 0 && str[i] == '-')
		{
			sign = -1;
		}
		else if (i == 0 && str[i] == '+')
		{
			continue;
		}
		else
		{
			if(str[i]>= '0' && str[i] <= '9')
			{
				num = num * 10 + sign * (str[i] - '0');
				if (sign == 1 && num > 0x7FFFFFFF || 
					sign == -1 && num < (signed int)0x80000000)
				{
					return INT_MAX;
				}
			}
			else
			{
				return INT_MAX;
			}
		}
	}
	return int(num);

}

string SimpleTest::int2str( int a )
{
	int tmp = a;
	int count = 0;
	if (tmp < 0)
	{
		tmp *= -1;
		count++;
	}
    while( tmp > 0)
	{
       tmp = tmp / 10;
	   count++;
	}
	char* str = new char[count];

	int i = 0;
	if(a < 0)
	{
		a *= -1;
		str[0] = '-';
	}
	tmp = a;
	while( tmp > 0)
	{
		int digit = tmp % 10;
		tmp = tmp / 10;
		str[count - i - 1] = char(digit + int('0'));
		i++;
	}

	return str;
}

void SimpleTest::testtransfer( void )
{
	string str[6] = {"-123", "+34", "3634", "34cg63f", "66548765245", "-75476474576457"};
	for (int i = 0; i < 6; ++i)
	{
		cout<<str[i]<<" "<<str2int(str[i])<<endl;
	}

	int a[2] = {123, -34};
	for(int i = 0; i < 2; ++i)
	{
		cout<<a[i]<<" "<<int2str(a[i])<<endl;
	}
}













