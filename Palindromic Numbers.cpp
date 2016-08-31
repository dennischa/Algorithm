#include <iostream>
#include <fstream>
#include <algorithm>

using namespace std;

int testCase;
int num;
int Convert[1002];
int n;
int ins;

bool palindromicNumbers;
bool a;


int main()
{
	ifstream file("input.txt");
	file >> testCase;

	while (testCase--)
	{
		file >> num;

		ins = num;
		palindromicNumbers = false;
		for (int i = 2; i <= 64; i++)
		{
			num = ins;
			n = 0;
			while (num >= i)
			{
				Convert[n] = num % i;
				num /= i;
				n++;
			}
			Convert[n] = num;			
			
			for (int j = 0; j < int((n+1)/2); j++)
			{
				a = true;
				if (Convert[j] != Convert[n - j])
				{
					a = false;
					break;
				}
			}

			if (a == true)
			{
				palindromicNumbers = true;
				break;				
			}
		}
		cout << (int)palindromicNumbers << endl;
	}

}