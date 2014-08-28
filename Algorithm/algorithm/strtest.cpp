#include "strtest.h"
#include <assert.h>


char* StrTest::myStrCpy( char* dest, const char* src )
{
	assert( (dest != NULL) && (src != NULL) );
	char *to = dest;
	while ( (*dest++ = *src++) != '\0' );
	return to;
}

char* StrTest::myStrCat( char* dest, const char* src )
{
	assert( (dest != NULL) && (src != NULL) );
	char *to = dest;
	while( *dest++ != '\0' );
	dest--;
	while( (*dest++ = *src++) != '\0' );
	return to;
}

void StrTest::testStrCpy(void)
{
	/*char dest1[10] = NULL;
	char *src1 = "abc";
	cout<<myStrCpy(dest1,src1)<<endl;*/

	char dest2[20] = "dsfgfgfd";
	char *src2 = "yufnn";
	
	cout<<myStrCpy(dest2,src2)<<endl;
}

void StrTest::testStrCat(void)
{
	char dest2[20] = "dsfgfgfd";
	char *src2 = "yufnn";

	cout<<myStrCat(dest2,src2)<<endl;
}

/////////////////////////////////////////////////////////////////////////////////////

int StrTest::findPos( const char* target, const char* pattern )
{
	if (target == NULL || pattern == NULL)
	{
		return -1;
	}
	for (unsigned int i = 0; i < strlen(target) - strlen(pattern) + 1; ++i)
	{
		unsigned int j;
 		for (j = 0; j < strlen(pattern); ++j)
		{
			if (target[i+j] != pattern[j])
			{
				break;
			}
		}
		if (j == strlen(pattern))   //attention: not need to minus 1
		{
			return i;
		}
	}
	return -1;
}

int StrTest::KMPFindPos(const char* target, const char* pattern)
{
	if (target == NULL || pattern == NULL)
	{
		return -1;
	}
	
	int i = 0;
	int j = 0;

	int lenT = strlen(target);
	int lenP = strlen(pattern);

	int* next = new int[lenP];
	getNext(next,pattern);

	while (i < lenT && j < lenP)
	{
		if (j == -1)
		{
			i++;
			j = 0;
		}
		else if(target[i] == pattern[j])   //attention
		{
			i++;
			j++;
		}
		else
		{
			j = next[j];
		}
	}
	if (j == lenP)
	{
		return i - lenP;     //attention: not i - lenP + 1
	}
	else
	{
		return -1;
	}
}


void StrTest::testFindPos( void )
{
	char* target = "dtadfgerbcbfds";
	//char* target = NULL;
	char* pattern = "bc";
	//cout<<findPos(target,pattern)<<endl;
	cout<<KMPFindPos(target,pattern)<<endl;
}

void StrTest::getNext(int* next, const char* pattern)
{
	next[0] = -1;
	int i = 0;
	int j = -1;

	int lenP = strlen(pattern);

	while (i < lenP)
	{
		if (j == -1 || pattern[i] == pattern[j])
		{
			++i;
			++j;
			next[i] = j;
		}
		else
		{
			j = next[j];
		}
	}
}

/////////////////////////////////////////////////////////////////////////////
bool StrTest::isPalindrome( int num )
{
	if (num < 0)
	{
		return false;
	}
	int origin = num;
	int n = 0;
	while (num > 0)
	{
		n = n * 10 + num % 10;
		num = num / 10;
	}
	return origin == n;
}

bool StrTest::isPalindrome2( int num )
{
	if (num < 0)
	{
		return false;
	}
	char* numstr = new char;
	_itoa(num,numstr,10);
	for (size_t i = 0; i < strlen(numstr)/2; ++i)   //strlen(numstr)/2 + 1  both ok
	{
		if (numstr[i] != numstr[strlen(numstr) - i - 1])
		{
			return false;
		}
	}
	return true;
}

void StrTest::testPalindrome( void )
{
	//int num = 3245;
	int num = 3456543;
	cout<<isPalindrome2(num)<<endl;
}

void StrTest::manacher(char s[], int length, int rad[])
{
	for (int i=1,j=0,k; i < length; i+=k) {
		while (s[i-j-1] == s[i+j+1]) ++j;
		rad[i] = j;
		for (k = 1; k <= rad[i] && rad[i-k] != rad[i]-k; ++k) { // 利用类似镜像的方法缩短了时间 
			rad[i+k] = min(rad[i-k], rad[i]-k);
		}
		j = max(j-k, 0);
	}
}


void StrTest::testManacher( void )
{
	const int N = 100;
	char str[N], cpy[N<<1];
	int seq[N<<1];
	while (scanf("%s", str) != EOF) {
		int len = strlen(str);
		cpy[0] = '(', cpy[1] = '#';
		for (int i=0, j=2; i < len; ++i, j+=2) {
			cpy[j] = str[i];
			cpy[j+1] = '#';
		}
		len = len*2+3;
		cpy[len-1] = ')';
		manacher(cpy, len, seq);
		int Max = 0;
		for (int i = 0; i < len; ++i) {
			Max = max(Max, seq[i]);
		}
		printf("%d\n", (Max-1)/2);
	}
}

int StrTest::findLongestPalindrome( const char* str)
{
	if (str == NULL)
	{
		return 0;
	}
	int lend;
	int rend;
	int lmax = 0;
	int index = 0;
	int count;
	int i;
	int len = strlen(str);
	for (i = 1; i < len; ++i)
	{
		lend = i - 1;
		rend = i + 1;
		count = 0;
		while (lend >= 0 && rend <= len - 1 && str[lend] == str[rend])
		{
			lend --;
			rend ++;
			count++;
		}
		if (count > lmax)
		{
			lmax = count;
			index = i;
		}
	}
	cout<<"no "<<index<<endl;
	return lmax*2 + 1;
}

void StrTest::testFindLongestPalindrome( void )
{
	char* str = "dgdfrtatrfr";
	cout<<findLongestPalindrome(str)<<endl;
}

void StrTest::leftRotate( char* str, int k )
{
	int len = strlen(str);
	if(str == NULL || k < 0 || k > len - 1)
	{
		return;
	}
	
	reverse(str, 0, k - 1);
	reverse(str, k, len - 1);
	reverse(str, 0, len - 1);
}

void StrTest::reverse( char* str, int start, int end )
{
	char tmp;
	while(start < end)
	{
       tmp = str[start];
	   str[start] = str[end];
	   str[end] = tmp;
	   start++;
	   end--;
	}
}

void StrTest::testLeftRotate( void )
{
	char str[] = "dgdfrtatrfr";
	leftRotate(str, 3);
	cout<<str<<endl;
}





