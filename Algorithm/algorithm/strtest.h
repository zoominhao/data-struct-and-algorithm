#pragma once

#include <iostream>
using namespace std;

class StrTest
{
public:
	char* myStrCpy(char* dest, const char* src);
	char* myStrCat(char* dest, const char* src);

	int findPos(const char* target, const char* pattern);
	int KMPFindPos(const char* target, const char* pattern);

	bool isPalindrome(int num);
	bool isPalindrome2(int num);
	
	void manacher(char s[], int length, int rad[]);

	void testStrCpy(void);
	void testStrCat(void);

	void testFindPos(void);
	void testPalindrome(void);

	void testManacher(void);

	//http://www.2cto.com/kf/201310/248225.html
	int findLongestPalindrome( const char* str);
	void testFindLongestPalindrome(void);

	//left rotate
	void leftRotate(char* str, int k);
	void reverse(char* str, int start, int end);
	void testLeftRotate(void);
private:
	void getNext(int* next, const char* pattern);

};