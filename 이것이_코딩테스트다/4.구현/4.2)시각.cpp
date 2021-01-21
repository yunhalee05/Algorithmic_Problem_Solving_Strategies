#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
#include <climits>
#include <string>

using namespace std;

int h, cnt;

bool Check(int h, int m, int s)
{
	if (h % 10 == 3 || m / 10 == 3 || m % 10 == 3 || s / 10 == 3 || s % 10 == 3)
		return true;
	return false;
}


int main() {
	cin >> h;
	for (int i = 0; i <= h; i++)
	{
		for (int j = 0; j < 60; j++)
		{
			for (int k = 0; k < 60; k++)
			{
				if (Check(i, j, k))
					cnt++;
			}
		}
	}
	cout << cnt << endl;


	return 0;
}