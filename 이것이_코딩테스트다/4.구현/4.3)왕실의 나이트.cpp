#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
#include <climits>
#include <string>

using namespace std;


int dx[8] = { 2, -2, 2, -2, 1, -1, 1, -1 };
int dy[8] = { -1, -1, 1, 1, 2, 2, -2, -2 };



int main() {
	int cnt = 0;
	string Now;
	cin >> Now;
	int x = (int)Now[0] - 97;
	int y = (int)Now[1] - 49;

	for (int i = 0; i < 8; i++)
	{
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (nx < 0 || ny < 0 || nx>7 || ny>7)
			continue;
		cnt++;
	}
	cout << cnt << endl;



	return 0;
}
