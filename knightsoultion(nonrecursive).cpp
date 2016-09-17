#include <iostream>
#include <fstream>
#include <algorithm>
using namespace std;

struct point {
	int x, y;
	int dir;
};
enum mark {
	MARK,
	UNMARK
};

struct direction {
	int x, y;
};

direction dir[8] = { { 1, -2},{ 2, -1 },{ 2, 1},{ 1, 2 },{ -1, 2 },{ -2, 1 },{ -2, -1 },{ -1, -2 } };
mark board[9][9];
point stack[65];


int path[9][9];
int testCase;

int main()
{
	ifstream file("input.txt");
	file >> testCase;
	while (testCase--)
	{
	
		int m, n, counter;
		point pos;

		file >> m >> n >> pos.y >> pos.x;

		for (int i = 0; i <= 65; i++)
			stack[i].dir = 0;

		for (int i = 1; i <= m; i++)
			for (int j = 1; j <= n; j++)
			{
				board[i][j] = UNMARK;
			}

		board[pos.y][pos.x] = MARK;
		path[pos.y][pos.x] = 1;
		
		//counter가 1일떄 
		counter = 1;
		stack[counter].x = pos.x;
		stack[counter].y = pos.y;
		stack[counter].dir = 0;

		while (1)
		{		
			point next;

			if (counter ==  m*n)
			{
				cout << 1 << endl;
				for (int i = 1; i <= m; i++)
				{
					for (int j = 1; j <= n; j++)
					{
						if (path[i][j] > 9)
							cout << path[i][j] << " ";
						else
							cout << " " << path[i][j] << " ";
					}
					cout << endl;
				}
				break;
			}		

			pos.x = stack[counter].x;
			pos.y = stack[counter].y;

			if (stack[counter].dir == 8)
			{
				//초기화
				board[pos.y][pos.x] = UNMARK;
				path[pos.y][pos.x] = 0;
				stack[counter].dir = 0;

				//한칸 뒤로
				counter--;
			}
			else
			{
				for (int i = stack[counter].dir; i < 8; i++)
				{
					next.x = pos.x + dir[i].x;
					next.y = pos.y + dir[i].y;

					if (next.x > 0 && next.x <= n && next.y > 0 && next.y <= m &&
						board[next.y][next.x] != MARK)
					{
						//실패시 다음 탐색 방향 기억
						stack[counter].dir = i + 1;
						
						//카운터 전진
						counter++;
						stack[counter].x = next.x;
						stack[counter].y = next.y;

						board[next.y][next.x] = MARK;
						path[next.y][next.x] = counter;
						break;
					}
					else if (i == 7)
					{
						//초기화
						board[pos.y][pos.x] = UNMARK;
						path[pos.y][pos.x] = 0;
						stack[counter].dir = 0;

						//한칸 뒤로
						counter--;
					}
				}
			}		
			if (counter == 0)
			{
				cout << 0 << endl;
				break;
			}
		}
		//초기화
		for (int i = 1; i <= m; i++)
			for (int j = 1; j <= n; j++)
			{
				board[i][j] = UNMARK;
			}

		


	}
}
