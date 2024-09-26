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
	cout << "* task 2: initialization randomized array *" << endl;
	int A[20];

	cout << endl << "your array:" << endl << "[ ";
	for (int i = 0; i < 20; i++)
	{
		A[i] = rand() % 202;
		cout << A[i] << " ";
	}
	cout << "]" << endl << endl << endl;

	//* task 3: initialization randomized dynamic array *
	cout << "* task 3: initialization randomized dynamic array *" << endl << endl;
	int i = 0;
	cout << "input array size" << endl;
	cin >> i;
	int* m = (int*)malloc(sizeof(int) * i);

	if (i == 0)
	{
		cout << endl << "array size cannot be zero" << endl;
		return;
	}
	else
	{
		cout << endl << "your array:" << endl << "[ ";
		for (int z = 0; z < i; z++, m++)
		{
			*m = rand() % 202;
			cout << *m << " ";
		}
		i--, m--;
		cout << "]" << endl << endl << endl;
	}

	//* task 1: difference between max and min element *
	cout << "* task 1: difference between max and min element *" << endl << endl;

	int max_m = 0, min_m = 1000;
	int max_p = 0, min_p = 0;

	for (; i != 0; i--, m--)
	{
		if (*m >= max_m) 
		{
			max_m = *m;
			max_p = i + 1;
		}
		if (*m <= min_m) 
		{
			min_m = *m;
			min_p = i + 1;
		}
	}

	cout << "greatest element is " << max_p << " and it = " << max_m << endl;
	cout << "smallest element is " << min_p << " and it = " << min_m << endl;
	cout << "difference = " << max_m - min_m << endl;
}