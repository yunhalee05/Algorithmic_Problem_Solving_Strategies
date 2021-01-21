#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
#include <climits>
#include <string>

using namespace std;


int dx[4] = { 0, 1, 0, -1 };//북, 동, 남, 서
int dy[4] = { -1, 0, 1, 0 };



int main() {
	int n, m, cnt = 1;
	cin >> n >> m;

	int x, y, direction;
	cin >> x >> y >> direction;//현재위치 정보와 방향을 입력받는다. 

	int Land[51][51];//땅의 정보를 받을 공간

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
			cin >> Land[i][j];
	}
	Land[x][y] = 1;//시작한 공간은 방문한 공간으로 다시 갈 수 없으므로 바다로 만든다. 

	while (true)
	{
		bool flag = false;
		for (int i = 0; i < 4; i++)//4방향으로 
		{
			direction -= 1;// 방향을 왼쪽으로 돌린다. 
			if (direction < 0) direction += 4;
			int nx = x + dx[direction];
			int ny = y + dy[direction];
			if (Land[nx][ny] == 0)//만약 왼쪽으로 돌린 방향으로 갈 수 있다면
			{
				x = nx; //이동한 후에 
				y = ny;
				flag = true;// 이동하는데 성공했다는 표시를 남기고 
				Land[nx][ny] = 1;//방문한 곳으로 표시한다. 
				cnt++;
				break;
			}
		}
		if (!flag)//만약 이동하지 못했다면 
		{
			if (Land[x - dx[direction]][y - dy[direction]] != 0) break;//뒤쪽으로 이동해보는데 이동할 수 없다면 그대로 종료한다. 
			else {//만약 이동이 가능하다면 뒤쪽으로 이동하고 다시 시작한다. 
				x -= dx[direction];
				y -= dy[direction];
				Land[x - dx[direction]][y - dy[direction]] = 1;//간 곳은 방문 표시해준다. 
				cnt++;
			}
		}
	}
	cout << cnt << endl;

	return 0;
}