#include <iostream>
#include <fstream>
#include <algorithm>
using namespace std;

int testCase;
int dy(int s, int e);
int n;
int* C;
int* S;
int** D;
int main()
{
	ifstream file("input.txt");
	file >> testCase;

	while (testCase--)
	{
		file >> n;
		C = new int[n + 1];
		S = new int[n + 1];
		D = new int*[n + 1];
		C[0] = 0;
		S[0] = 0;
		D[0] = new int[n + 1];

		for (int i = 1; i < n + 1; i++) {
			file >> C[i];
			S[i] = S[i - 1] + C[i];
			D[i] = new int[n + 1];
		}

		for (int i = 0; i < n + 1; i++)
			for (int j = 0; j < n + 1; j++) {
				D[i][j] = 0;
			}
		for (int i = 1; i < n + 1; i++) {
			for (int j = 1; j < n + 1; j++) {
			}
		}
		for (int i = 1; i < n + 1; i++) {
			int j = 1;
			for (int k = i; k < n + 1; k++) {
				D[j][k] = dy(j, k);
				j++;
			}
		}

		cout << D[1][n] << endl;
	}
	file.close();
}

int dy(int s, int e) {
	if (s > e)
		return 0;
	if (s == e)
		return C[s];
	if (D[s][e] > 0)
		return D[s][e];
	int sum = S[e] - S[s - 1];
	return max(sum - D[s][e - 1], sum - D[s + 1][e]);
}