#include <iostream>
#include <vector>

using namespace std;

bool friends[10][10];
bool taken[10];
int Count = 0;


void countPairing();
int n, m;

void makefriends(int x)
{
	for (int i = 0; i < x; i++)
	{
		for (int j = 0; j < x; j++)
		{
			friends[i][j] = false;
		}
	}
	for (int i = 0; i < x; i++)
	{
		taken[i] = false;
	}
}


int main()
{
	int c;
	cin >> c;
	vector<int>answer;

	for (int i = 0; i < c; i++)
	{
		cin >> n >> m;

		makefriends(n);

		for (int j = 0; j < m; j++)
		{
			int a, b;
			cin >> a >> b;
			friends[a][b] = true;
			friends[b][a] = true;
		}

		countPairing();

		answer.push_back(Count);

		Count = 0;
	}
	for (int i = 0; i < c; i++)
	{
		cout << answer[i] << endl;
	}

	return 0;
}
void countPairing()
{
	int index = -1;
	for (int i = 0; i < n; i++)
	{
		if (taken[i] == false)
		{
			index = i;
			break;
		}
	}
	if (index == -1) { Count += 1;  return; }

	for (int i = index + 1; i < n; i++)
	{
		if (!taken[index] && !taken[i] && friends[index][i])
		{
			taken[index] = taken[i] = true;
			countPairing();
			taken[index] = taken[i] = false;
		}
	}

	return;
}