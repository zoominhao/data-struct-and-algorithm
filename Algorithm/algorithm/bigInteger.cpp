#include "bigInteger.h"

void BigInteger::add( int num1[], int num2[], int num3[] )
{
	for (int i = 0; i < N; ++i)
	{
		num3[i] = 0;
	}
	for (int i = 0; i < N; ++i)
	{
		num3[i] = num1[i] + num2[i] + num3[i];
		if (num3[i] >= 10)
		{
			num3[i] -= 10;
			num3[i+1] ++;
		}
	}
}

void BigInteger::sub( int num1[], int num2[], int num3[] )
{
	for (int i = 0; i < N; ++i)
	{
		num3[i] = 0;
	}
	for (int i = 0; i < N; ++i)
	{
		num3[i] = num1[i] - num2[i] + num3[i];
		if (num3[i] < 0)
		{
			num3[i + 1]--;
			num3[i] += 10;
		}
	}
}

void BigInteger::multiple( int num1[], int num2[], int num3[] )
{
	for (int i = 0; i < N*2; ++i)
	{
		num3[i] = 0;
	}
	for (int i = 0; i < N; ++i)
	{
	    for (int j = 0; j < N; ++j)
	    {
			num3[i + j] = num1[i] * num2[j] + num3[i + j];
			if (num3[i + j] >= 10)
			{
				num3[i + j + 1] += num3[i + j] / 10;
				num3[i + j] %= 10;
			}
	    }
	}
}

void BigInteger::print( int num[] )
{
	int i;
	for(i = N - 1; i >= 0; --i)
	{
		if (num[i] != 0)
		{
			break;
		}
	}

	if(i == -1){
		cout<<0;
	}else{
		for(int j = i; j >= 0; --j){
			cout<<num[j];
		}
	}
	cout<<endl;
}


void BigInteger::testBigInteger( void )
{
	char str1[N];
	char str2[N];
	cin>>str1>>str2;
	int num1[N] = {0};
	int num2[N] = {0};
	int num3[N] = {0};
	int num4[2*N] = {0};
	const int str1_len = strlen(str1);
	const int str2_len = strlen(str2);
	int i, j;
	j = 0;
	for(i = str1_len - 1; i >= 0; --i){
		num1[j++] = str1[i] - '0';
	}
	j = 0;
	for(i = str2_len - 1; i >= 0; --i){
		num2[j++] = str2[i] - '0';
	}
	//1. add
	add(num1, num2, num3);
	print(num3);
	//2. sub
	int sign = strcmp(str1, str2);
	if (sign >= 0){
		sub(num1, num2, num3);
	}else{
		sub(num2, num1, num3);
	}
	if(sign < 0) cout<<"-";
	print(num3);
	//3. mul
	multiple(num1, num2, num4);
	print(num4);
}

