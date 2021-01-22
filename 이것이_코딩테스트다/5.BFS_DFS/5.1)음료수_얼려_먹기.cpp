#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
#include <climits>
#include <string>

using namespace std;
int n, m;
int Ice[1000][1000];

bool dfs(int x, int y) {
	if (x <= -1 || x >= n || y <= -1 || y >= m)//������ �����ϴ��� Ȯ��
	{
		return false;
	}

	if (Ice[x][y] == 0)//���� �ִ� �����̶��
	{
		Ice[x][y] = 1;//�湮ǥ�� ����� 
		dfs(x + 1, y);//�����¿� �湮
		dfs(x - 1, y);
		dfs(x, y + 1);
		dfs(x, y - 1);
		return true;
	}

	return false;//�湮�� �� �ִ� ������ ���ٸ� ���� false

}

int main() {
	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++)
		{
			cin >> Ice[i][j];
		}
	}

	int cnt = 0;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (dfs(i, j))//true ��� ���̽�ũ�� �ϳ� ����
			{
				cnt++;
			}
		}
	}

	cout << cnt << endl;
}




/* ó���� § �ڵ� (���൵ �ȵȴ�)

int n, m, cnt=0;
int Ice[1000][1000];
int dx[4] = { 0,0,1,-1 };
int dy[4] = { 1, -1, 0, 0 };


int Cream(int Start, int End) {
	for (int i = 0; i < 4; i++)
	{
		int newStart = Start + dx[i];
		int newEnd = End + dy[i];
		if (Ice[newStart][newEnd] == 0) {
			Ice[newStart][newEnd] = 1;
			Cream(newStart, newEnd);
		}
	}
	cnt++;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (Ice[i][j] == 0)
				Cream(i, j);
		}
	}
	return cnt;

}

int main() {
	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++)
		{
			cin >> Ice[i][j];
		}
	}
	Ice[0][0]= 1;
	Cream(0, 0);
	cout << cnt << endl;

	return 0;
}
*/