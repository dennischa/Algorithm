#include <iostream>
#include <fstream>
#include <algorithm>
using namespace std;

struct point { int x, y; };
enum mark {
	MARK,
	UNMARK
};
point dir[8] = { {1, -2},{ 2, -1 },{ 2, 1 },{ 1, 2 },{ -1, 2 },{ -2, 1 },{ -2, -1 },{ -1, -2 } };
mark board[9][9];
int path[9][9];
int testCase;
int knightTour(int m, int n, point pos, int counter);
int main()
{
	ifstream file("input.txt");
	file >> testCase;

	while (testCase--)
	{
		int m, n, counter;
		point pos;

		file >> m >> n >> pos.y >> pos.x;

		for (int i = 1; i <= m; i++) 
			for (int j = 1; j <= n; j++)
			{
				board[i][j] = UNMARK;
			}

		board[pos.y][pos.x] = MARK; 
		path[pos.y][pos.x] = 1;

		if (knightTour(m, n, pos, 1))
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
		}
		else
			cout << 0 << endl;

	}
}

int knightTour(int m, int n, point pos, int counter)
{
	point next;

	if (counter == m * n)
		return 1;

	for (int i = 0; i < 8; i++)
	{
		next.x = pos.x + dir[i].x;
		next.y = pos.y + dir[i].y;

		if (next.x > 0 && next.x <= n && next.y > 0 && next.y <= m &&
			board[next.y][next.x] != MARK)
		{
			board[next.y][next.x] = MARK;
			path[next.y][next.x] = counter + 1;

			if (knightTour(m, n, next, counter + 1))
				return 1;

			board[next.y][next.x] = UNMARK;
		}
	}

	return 0;
}