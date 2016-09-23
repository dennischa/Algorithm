#include <iostream>
#include <fstream>
#include <algorithm>

/*The 36th
Annual ACM
International Collegiate Programming Contest
Asia Regional – Daejeon
Nationwide Internet Competition
Problem I
Two Numbers*/
using namespace std;

int testCase;
int num;
int k;
int temp;

int arr[100000003] = { 0, };
int main()
{
	ifstream file("input.txt");
	file >> testCase;

	while (testCase--)
	{
		file >> num >> k;

		for (int i = 0; i < num; i++)
			file >> arr[i];
		int str = 0;
		int end = num - 1;
		sort(arr, arr + num);

		int min = 1000000001;
		int count = 0;
		while (str < end)
		{
			int temp = abs(arr[str] + arr[end] - k);
			
			if (arr[str] + arr[end] <= k)
			{
				if (temp < min)
				{
					min = temp;
					count = 1;
				}
				else if (temp == min)
					count++;

				str++;
			}
			else if (arr[str] + arr[end] > k)
			{
				if (abs(arr[str] + arr[end] - k) < min)
				{
					min = abs(arr[str] + arr[end] - k);
					count = 1;
				}
				else if (temp == min)
					count++;				
				
				end--;
			}
		}
		cout << count << endl;
	}
}