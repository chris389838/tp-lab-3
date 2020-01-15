#define _CRT_SECURE_NO_WARNINGS
#include "DateTime.h"
#include <iostream>

using namespace std;
int main()
{
	DateTime dt(31, 10, 2018);
	cout << dt.getTomorrow() << endl;
	DateTime dt2(1, 11, 2018);
	cout << dt2.getTomorrow() << endl;
	cout << dt2.getToday() << endl;
	DateTime dt3(20, 11, 2018);
	DateTime dt4(20, 11, 2018);
	cout << dt3.getDifference(dt4) << endl;
	DateTime dt5(20, 11, 2018);
	DateTime dt6(21, 11, 2018);
	cout << dt5.getDifference(dt6) << endl;
}