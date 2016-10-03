#include <iostream>
#include <fstream>
#include <algorithm>
using namespace std;

int testCase;
int gcd(int a, int b) {
	if (b == 0)
		return a;

	return gcd(b, a%b);
}
int main()
{
	ifstream file("input.txt");
	file >> testCase;

	while (testCase--)
	{
		int a, b;
		file >> a >> b;

		cout << gcd(a, b) << endl;
	}
}