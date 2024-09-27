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
	int A[20] = {};

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
	for (int j = 0; j < 5; j++)
	{
		for (int i = 0; i < 5; i++)
		{
			column_sum += N[i][j];
		}
		cout << setw(8) << column_sum;
		column_sum = 0;
	}
	cout << setw(9) << "sum" << endl << endl;

	//* task 5: search in struct *
	cout << "* task 5: search in struct *" << endl << endl;

	string l_names[] = { "Makarov", "Vidyaev", "Usov", "Kazakov", "Kuzmin", "Jiganov", "Yurov", "Pilnov" };
	string names[] = { "Daniil", "Alexander", "Alexey", "Vladimir", "Denis", "Anton", "Maksim", "Nikita" };
	string faculty[] = { "FVT", "FITE", "PTET", "Ist-Fil", "PED", "YUR-Fak", "Econom", "MED" };
	string grade_book_num[] = { "23VVV1312", "21VI32", "24IPO231", "19LL13234", "22NS13", "23ZMOS412", "23ZFPB11", "17KE242" };

	struct student
	{
		string famil, name, facult, Nomzach;
	} stud[10], tmp_stud[10];
	int x = 0;
	int temp_type = 0;
	string temp_value;
	int c = 0;

	cout << "All students:" << endl << setw(20) << "last name" << setw(20) << "name" << setw(20) << "faculty" << setw(20) << "gr book num" << endl << endl;

	for (int i = 0; i < 10; i++)
	{
		x = rand() % 8;
		stud[i].famil = l_names[x];
		x = rand() % 8;
		stud[i].name = names[x];
		x = rand() % 8;
		stud[i].facult = faculty[x];
		x = rand() % 8;
		stud[i].Nomzach = grade_book_num[x];
		cout << setw(20) << stud[i].famil << setw(20) << stud[i].name << setw(20) << stud[i].facult << setw(20) << stud[i].Nomzach << endl;
	}

	cout << endl << "enter search parameter" << endl << "(last name = 1 | name = 2 | faculty = 3 | grade book number = 4):" << endl;
	cin >> temp_type;
	cout << endl << "enter search value:" << endl;
	cin >> temp_value;
	switch (temp_type)
	{
	case 1:
	{
		for (int i = 0; i < 10; i++)
		{
			if (stud[i].famil == temp_value)
			{
				tmp_stud[c] = stud[i];
				c++;
			}
		}
		break;
	}
	case 2:
	{
		for (int i = 0; i < 10; i++)
		{
			if (stud[i].name == temp_value)
			{
				tmp_stud[c] = stud[i];
				c++;
			}
		}
		break;
	}
	case 3:
	{
		for (int i = 0; i < 10; i++)
		{
			if (stud[i].facult == temp_value)
			{
				tmp_stud[c] = stud[i];
				c++;
			}
		}
		break;
	}
	case 4:
	{
		for (int i = 0; i < 10; i++)
		{
			if (stud[i].Nomzach == temp_value)
			{
				tmp_stud[c] = stud[i];
				c++;
			}
		}
		break;
	}
	default:
	{
		cout << "error. must type 1 to 4." << endl << endl;
		return;
	}
	}

	if (c <= 0)
	{
		cout << endl << "error. check entered value, it's wrong" << endl << endl;
	}
	else
	{
		for (int i = 0; i < c; i++)
		{
			cout << endl << "Information about student:" << endl << "last name: " << tmp_stud[i].famil << endl << "name: " << tmp_stud[i].name << endl << "faculty: " << tmp_stud[i].facult << endl << "grade book number: " << tmp_stud[i].Nomzach << endl << endl;
		}
	}
}