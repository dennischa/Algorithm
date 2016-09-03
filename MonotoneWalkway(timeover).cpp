#include <iostream>
#include <fstream>
#include <algorithm>

using namespace std;


int testCase;
int n;
int temp;
int sum;
int c;
int a, b;
int ud;

struct point {
	int x;
	int y;

	/*bool operator <(const point &b)const {
		return this->x < b.x;
	}*/
};

bool xcmpdown(const point &a, const point &b)
{
	if (a.x == b.x)
		return a.y < b.y;
	
	return a.x < b.x;
}

bool ycmpup(const point &a, const point &b)
{
	return a.y > b.y;
}

point p[100002] = { 0,};

int main()
{
	ifstream file("input.txt");
	file >> testCase;

	while (testCase--)
	{
		file >> n;
		p[100002] = { 0, 0 ,};
		//자료입력
		for (int i = 1; i < n + 1; i++)
		{
			file >> p[i].x;
			file >> p[i].y;
		}
		

		sort(p + 1 , p + n + 1 , xcmpdown);	
		for (int i = 2; i < n + 2; i++)
		{
			if (p[i].x == p[i - 1].x)
			{
				c = 2;
				temp = i;
				for (int j = i; j < n + 1; j++)
				{					
					if (p[j].x == p[j + 1].x)
					{
						c++;
					}
					else
					{
						temp = j;						
						break;
					}
				}
				if (p[i-2].y != p[i-1].y)
					sort(p + i -1 , p + i - 1  + c  , ycmpup);		
				i = temp;
			}			
		}
		
		file >> a;
		for (int i = 0; i < a; i++)
		{
			file >> b;
			cout << p[b].x << " " << p[b].y << endl;
		}

	}
}
