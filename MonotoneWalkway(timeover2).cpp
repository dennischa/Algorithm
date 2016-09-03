#include <iostream>
#include <fstream>
#include <algorithm>

using namespace std;


int testCase;
int n;

struct point {
	int x;
	int y;
	int cafeNumber;
};

point p[100010] = { 0,0,-1 };

int ppnum;
int pnum;
bool ins;
int cafe;
int Emin;


int main()
{
	point main;
	ifstream file("input.txt");
	file >> testCase;
	
	while (testCase--)
	{
		file >> n;

		main.x = 0;
		main.y = 0;

		for (int i = 0; i < n; i++)
		{
			file >> p[i].x;
			file >> p[i].y;
			p[i].cafeNumber = -1;
			//cout << i << " "<< p[i].x <<" " << p[i].y << endl;
		}

		ins = false;

		for (int j = 0; j < n; j++)
		{
			Emin = 200010;
			for (int i = 0; i < n; i++)
			{
				if (main.x == p[i].x)
				{
					if (Emin > abs(main.y - p[i].y) && p[i].cafeNumber == -1)
					{
						Emin = min(Emin, abs(main.y - p[i].y));
						cafe = i;
						ins = true;
					}
				}
			}

			if (ins == false)
			{
				for (int i = 0; i < n; i++)
				{
					if (main.y == p[i].y)
					{
						if (Emin > abs(main.x - p[i].x) && p[i].cafeNumber == -1)
						{
							Emin = min(Emin, p[i].x- main.x);
							cafe = i;
						}
					}
				}
			}

			ins = false;

			p[cafe].cafeNumber = j + 1;
			main.x = p[cafe].x;
			main.y = p[cafe].y;

			//cout << cafe << " "<< p[cafe].x << " " << p[cafe].y << endl;

			ins = false;
		}
		
		file >> ppnum;
		for (int i = 0; i < ppnum; i++)
		{
			file >> pnum;
			for (int j = 0; j < n; j++)
			{
				if (p[j].cafeNumber == pnum)
				{
					cout << p[j].x << " " << p[j].y << endl;
					break;
				}
			}
		}
	}
}
