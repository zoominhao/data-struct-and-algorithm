#pragma once
#include <iostream>
using namespace std;

struct Date
{
	int year;
	int month;
	int day;
};

class SimpleTest
{
public:
	int getAbsDays(Date date);
	int getDateDiff(Date date1, Date date2);

	void testDaysDiff(void);
};