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
int dx[4] = { -1, 1, 0,0 };//상하좌우 방향
int dy[4] = { 0,0,-1,1 };


int dfs(int x, int y) {
	queue <pair<int, int>> q;//BFS문제를 사용하기 위해서 queue사용
	q.push({ x,y });

	while (!q.empty())//큐가 빌때까지
	{
		int x = q.front().first;//제일 먼저 들어온 값으로 설정
		int y = q.front().second;
		q.pop();//제일 먼저 들어온 값 제거


		for (int i = 0; i < 4; i++)
		{
			int nx = x + dx[i];//새로운 방향 설정
			int ny = y + dy[i];

			if (nx<0 || ny<0 || nx>n - 1 || ny>m - 1) continue;//범위에서 벗어나면 다음것으로 이동

			if (Maze[nx][ny] == 0) continue;//괴물이 있는 공간이면 다음 범위로 이동

			if (Maze[nx][ny] == 1)//한번도 방문하지 않은 괴물이 없는 공간이면 
			{
				Maze[nx][ny] = Maze[x][y] + 1;//방문하고 이동거리 더해준다. 
				q.push({ nx, ny });//큐에 추가 
			}
		}
	}

	return Maze[n - 1][m - 1];//제일 끝값(최소로 이동한 값)계산

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


/* 처음에 한 코드(실행도 안된다)
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
