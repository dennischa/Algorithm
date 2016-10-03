#include <iostream>
#include <fstream>
#include <algorithm>
#include<functional>
using namespace std;
int testCase;

int rec(int n)
{
	if (n == 0)
		return 1;

	return n * rec(n - 1);
};

int main()
{
	ifstream file("input.txt");
	file >> testCase;

	while (testCase--)
	{
		int tmp;
		file >> tmp;
		cout << rec(tmp) << endl;

	}
}