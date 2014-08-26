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


