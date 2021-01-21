#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
#include <climits>
#include <string>

using namespace std;

int n;
string A;
int x = 1;
int y = 1;

int dx[4] = { 0,0,-1,1 };
int dy[4] = { -1,1,0,0 };

char movetypes[4] = { 'L', 'R', 'U', 'D' };

int main() {

	cin >> n;
	cin.ignore();//버퍼 비우기

	getline(cin, A);
	for (int i = 0; i < A.length(); i++)
	{
		int nx;
		int ny;
		for (int j = 0; j < 4; j++)
		{
			if (A[i] == movetypes[j])
			{
				nx = x + dx[j];
				ny = y + dy[j];
			}
		}
		if (nx <1 || nx > n || ny <1 || ny > n)
			continue;
		x = nx;
		y = ny;
	}
	cout << "(" << x << "," << y << ")" << endl;








	/* 처음에 짠 코드

	int n;
	string A;
	int Now[2] = { 1, 1 };

	cin >> n;
	cin >> A;
	for (int i = 0; i < A.length(); i++)
	{
		if (A[i] == 'L')
		{
			if (Now[1] - 1 < 1)
				continue;
			Now[1] -= 1;
		}
		else if (A[i] == 'R')
		{
			if (Now[1] + 1 < n)
				continue;
			Now[1] += 1;
		}
		else if (A[i] == 'U')
		{
			if (Now[0] - 1 < 1)
				continue;
			Now[0] -= 1;
		}
		else
		{
			if (Now[0] + 1 < n)
				continue;
			Now[0] += 1;
		}
	}

	cout << "(" << Now[0] << "," << Now[1] << ")" << endl;

	*/
	return 0;
}
