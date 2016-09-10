#include <iostream>
#include <fstream>
#include <algorithm>
using namespace std;

int testCase;

int a[1000][1000];
int num;
int b;

bool temp;

enum Loop
{
	ZERO,
	LOOP,
	NO
};

Loop l;

int main()
{
	ifstream file("input.txt");
	file >> testCase;

	while (testCase--)
	{
		b = 0;
		file >> num;

		for (int i = 0; i < num; i++)
			file >> a[b][i];

		b++;

		while (true)
		{
			for (int i = 0; i < num; i++)
			{
				if (i == num - 1)
					a[b][i] = abs(a[b - 1][i] - a[b - 1][0]);
				else
					a[b][i] = abs(a[b - 1][i + 1] - a[b - 1][i]);
			}

			l = ZERO;

			for (int i = 0; i < num; i++)
			{
				if (a[b][i] != 0)
				{
					l = NO;
					break;
				}
			}

			if (l == ZERO)
				break;

			l = NO;

			for (int i = 0; i < b; i++)
			{
				temp = true;
				for (int j = 0; j < num; j++)
					if (a[i][j] != a[b][j])
					{
						temp = false;
						break;
					}

				if (temp == true)
				{
					l = LOOP;
					break;
				}
			}

			if (l == LOOP)
				break;

			b++;
		}

		switch (l)
		{
		case LOOP:
			cout << "LOOP" << endl;
			break;
		case ZERO:
			cout << "ZERO" << endl;
		}		
	}
}

