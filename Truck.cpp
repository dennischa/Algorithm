#include <iostream>
#include <fstream>
#include <algorithm>
#include <queue>
using namespace std;

int testCase;

struct truck {
	int w;
	int eT;
};


int main()
{
	ifstream file("input.txt");
	file >> testCase;

	while (testCase--)
	{
		int n, w, l;
		file >> n >> l >> w;

		queue<truck> wait;
		queue<truck> ing;

		for (int i = 0; i < n; i++) {
			truck tmp;
			file >> tmp.w;
			tmp.eT = 0;
			wait.push(tmp);
		}

		int wgt = 0;
		int time = 1;

		while (!wait.empty() || !ing.empty()) {
			
			
			if (!wait.empty()) {
				if (ing.size() <= l && wgt + wait.front().w <= w) {
					truck tmp = wait.front();
					wgt += tmp.w;
					tmp.eT = time-1;
					ing.push(tmp);
					wait.pop();
				}
			}

			if (time - ing.front().eT == l) {
				truck tmp = ing.front();
				wgt -= tmp.w;
				ing.pop();
			}
			
			time++;
		}

		cout << time << endl;
	}
}