#include <iostream>
#include <fstream>
#include <algorithm>
using namespace std;
int GCD(int a, int b);
int testCase, t;
unsigned int a;
unsigned int son;
unsigned int mom;

int main()
{
	ifstream file("input.txt");
	file >> testCase;

	while (testCase--)
	{
		file >> son;
		file >> mom;

		while (son != 1)
		{
			a = (int)(mom / son) + 1;
			son = (son * a) - mom;
			mom = mom * a;
			
			t = GCD(mom, son);
			mom /= t;
			son /= t;
		}
		cout << mom << endl;
	}
	file.close();
}

int GCD(int a, int b)
{
	while (true)
	{
		a %= b;
		if (a == 0)
			return b;
		b %= a;
		if (b == 0)
			return a;
	}
}
