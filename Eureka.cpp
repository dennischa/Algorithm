#include <iostream>
#include <fstream>
#include <algorithm>

/*The 39th Annual
ACM International Collegiate
Programming Contest
Asia Regional - Daejeon
Problem C
Eureka Theorem */
using namespace std;

int testCase;
int w, h, n;
int arr[100000000] = { 0, };

int main()
{
	ifstream file("input.txt");
	file >> testCase;

	while (testCase--)
	{
		for (int i = 1; i <= 45;i++)
			for (int j = 1; j <= i; j++)
				for (int l = 1; l <= i;l++)
					arr[(i*i + j*j + l*l + i + j + l) / 2] = 1;

		int temp;
		file >> temp;

		cout << arr[temp] << endl;
	}
}
