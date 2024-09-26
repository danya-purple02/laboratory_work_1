#define _CRT_SECURE_NO_WARNINGS
#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <time.h>
using namespace std;

void main()
{
	srand(time(NULL));

	//* task 2: initialization randomized array *
	cout << "* task 2: initialization randomized array *" << endl << endl;
	int i = 0;
	cout << "input array size" << endl;
	cin >> i;
	int* m = (int*)malloc(sizeof(int) * i);

	if (i == 0)
	{
		cout << endl << "array size cannot be zero" << endl;
	}
	else
	{
		cout << endl << "your array:" << endl << "[ ";
		for (int z = 0; z < i; z++, m++)
		{
			*m = rand() % 202;
			cout << *m << " ";
		}
		cout << "]" << endl << endl;
	}


}