#define _CRT_SECURE_NO_WARNINGS
#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <time.h>
#include <iomanip>
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
	int z = 0;
	cout << "input array size" << endl;
	cin >> z;
	int* m = (int*)malloc(sizeof(int) * z);

	if (z == 0)
	{
		cout << endl << "array size cannot be zero" << endl;
		return;
	}
	else
	{
		cout << endl << "your array:" << endl << "[ ";
		for (int i = 0; i < z; i++, m++)
		{
			*m = rand() % 202;
			cout << *m << " ";
		}
		m--;
		cout << "]" << endl << endl << endl;
	}

	//* task 1: difference between max and min element *
	cout << "* task 1: difference between max and min element *" << endl << endl;

	int max_m = 0, min_m = 1000;
	int max_p = 0, min_p = 0;

	for (; z != 0; z--, m--)
	{
		if (*m >= max_m) 
		{
			max_m = *m;
			max_p = z;
		}
		if (*m <= min_m) 
		{
			min_m = *m;
			min_p = z;
		}
	}

	cout << "greatest element is " << max_p << " and it = " << max_m << endl;
	cout << "smallest element is " << min_p << " and it = " << min_m << endl;
	cout << "difference = " << max_m - min_m << endl;
	cout << endl << endl;
	//* task 4: row and column sums *
	cout << "* task 4: row and column sums *" << endl << endl;

	int N[5][5];
	int row_sum = 0, column_sum = 0;

	cout << "generated matrix: " << endl;
	for (int i = 0; i < 5; i++) 
	{
		if (i == 0) cout << "/";
		if (i != 0 && i != 4) cout << "|";
		if (i == 4) cout << "\\";
		for (int j = 0; j < 5; j++)
		{
			N[i][j] = rand() % 202;
			cout << setw(7) << N[i][j] << " ";
			row_sum += N[i][j];
		}
		if (i == 0) cout << "\\";
		if (i != 0 && i != 4) cout << "|";
		if (i == 4) cout << "/";
		cout << setw(7) << row_sum << endl;
		row_sum = 0;
	}
	cout << endl;
	for (int j = 0; j < 5; j ++) 
	{
		for (int i = 0; i < 5; i++) 
		{
			column_sum += N[i][j];
		}
		cout << setw(8) << column_sum;
		column_sum = 0;
	}
	cout << setw(9) << "sum" << endl << endl;
}