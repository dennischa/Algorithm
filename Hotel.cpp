#include <iostream>
#include <fstream>
#include <algorithm>

/*The 39th Annual ACM
International Collegiate Programming Contest
Asia Regional – Daejeon
Korea Nationwide Internet Competition
Problem A
ACM Hotel*/
using namespace std;

int testCase;
int w, h, n;

int main()
{
	ifstream file("input.txt");
	file >> testCase;

	while (testCase--)
	{
		file >> h >> w >> n;
		int temp = n / h;
		int temp2 = n % h;
		
		int count = 1;
		if (n%h == 0)
		{
			temp2 = h;
			count = 0;
		}

		cout << temp2;

		if (temp + count >= 10)
			cout << temp + count << endl;
		else
			cout << "0" << temp + count << endl;

	}
}