#include <iostream>
#include <fstream>
#include <algorithm>
using namespace std;

int testCase;
int thenumberofTeam;
int thenumberofMatch;
int t;

int teamA, teamB;
int scoreA, scoreB;

int score[1024];
int allow[1024];

int main()
{
	ifstream file("input.txt");
	file >> testCase;

	while (testCase--)
	{
		double Emax = 0;
		double Emin = 1;

		double pythagoreanExpectation = 0;

		file >> thenumberofTeam >> thenumberofMatch;

		for (int i = 1; i < thenumberofTeam + 1; i++)
		{
			score[i] = 0;
			allow[i] = 0;
		}

		for (int i = 0; i < thenumberofMatch; i++)
		{
			file >> teamA >> teamB >> scoreA >> scoreB;
			score[teamA] += scoreA;
			score[teamB] += scoreB;

			allow[teamA] += scoreB;
			allow[teamB] += scoreA;

		}

		for (int i = 1; i < thenumberofTeam + 1; i++)
		{
			if (score[i] + allow[i])
				pythagoreanExpectation = (double)(score[i] * score[i]) / (score[i] * score[i] + allow[i] * allow[i]);
			else
				pythagoreanExpectation = 0;
			//cout << pythagoreanExpectation << endl;
			Emax = max(Emax, pythagoreanExpectation);
			Emin = min(Emin, pythagoreanExpectation);
		}

		cout << int(Emax * 1000) << endl;
		cout << int(Emin * 1000) << endl;
	}
	
}
