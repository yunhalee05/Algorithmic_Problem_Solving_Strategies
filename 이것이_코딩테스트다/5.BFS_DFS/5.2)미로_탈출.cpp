#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
#include <climits>
#include <string>
#include <queue>

using namespace std;
int n, m;
int Maze[200][200];
int dx[4] = { -1, 1, 0,0 };//�����¿� ����
int dy[4] = { 0,0,-1,1 };


int dfs(int x, int y) {
	queue <pair<int, int>> q;//BFS������ ����ϱ� ���ؼ� queue���
	q.push({ x,y });

	while (!q.empty())//ť�� ��������
	{
		int x = q.front().first;//���� ���� ���� ������ ����
		int y = q.front().second;
		q.pop();//���� ���� ���� �� ����


		for (int i = 0; i < 4; i++)
		{
			int nx = x + dx[i];//���ο� ���� ����
			int ny = y + dy[i];

			if (nx<0 || ny<0 || nx>n - 1 || ny>m - 1) continue;//�������� ����� ���������� �̵�

			if (Maze[nx][ny] == 0) continue;//������ �ִ� �����̸� ���� ������ �̵�

			if (Maze[nx][ny] == 1)//�ѹ��� �湮���� ���� ������ ���� �����̸� 
			{
				Maze[nx][ny] = Maze[x][y] + 1;//�湮�ϰ� �̵��Ÿ� �����ش�. 
				q.push({ nx, ny });//ť�� �߰� 
			}
		}
	}

	return Maze[n - 1][m - 1];//���� ����(�ּҷ� �̵��� ��)���

}

int main() {
	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++)
		{
			cin >> Maze[i][j];
		}
	}

	cout << dfs(0, 0) << endl;;

	return 0;

}


/* ó���� �� �ڵ�(���൵ �ȵȴ�)
int dfs(int Start, int End, int cnt) {
	if (Start == n-1 && End == m-1)
	{
		cnt++;
		if (cnt < Min)
		{
			Min = cnt;
			return Min;
		}
	}
	if (Start >= n || Start < 0 || End >= n || End < 0) return Min;

	if (Maze[Start][End] == 1)
	{
		cnt++;
		dfs(Start + 1, End, cnt);
		dfs(Start - 1, End, cnt);
		dfs(Start, End + 1, cnt);
		dfs(Start, End - 1, cnt);
	}

	return Min;

}

int main() {
	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++)
		{
			cin >> Maze[i][j];
		}
	}

	dfs(0, 0, 0);

	cout << Min << endl;


}
*/
