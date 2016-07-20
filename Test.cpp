#define _CRT_SECURE_NO_WARNINGS 1

#include <iostream>
using namespace std;
#include "vector.h"
#include"List.h"
#include <stdarg.h>

int main()
{
	//TestVector1();
	TestList();

	long long a = 1, b = 2, c = 3;
	//01 00 00 00  00 00 00 00  
	//02 00 00 00  00 00 00 00 
	//03 00 00 00 00 00 00 00 
	/*va_start*/
	//while循环非零的值，都是正确的
	/*while (-1)
	{
		cout << 1 << endl;
	}*/
	cout << sizeof(long long) << endl;
	printf("%d %d %d", a, b, c);
	system("pause");
	return 0;
}