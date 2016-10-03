#include <iostream>
#include <fstream>

using namespace std;
int testCase;

int rec(int n)
{
	if (n == 0)
		return 0;
	if (n == 1)
		return 1;
	
	return rec(n-2) + rec(n - 1);
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