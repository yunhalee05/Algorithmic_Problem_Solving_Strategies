#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
#include <climits>
#include <string>

using namespace std;


int dx[4] = { 0, 1, 0, -1 };//��, ��, ��, ��
int dy[4] = { -1, 0, 1, 0 };



int main() {
	int n, m, cnt = 1;
	cin >> n >> m;

	int x, y, direction;
	cin >> x >> y >> direction;//������ġ ������ ������ �Է¹޴´�. 

	int Land[51][51];//���� ������ ���� ����

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
			cin >> Land[i][j];
	}
	Land[x][y] = 1;//������ ������ �湮�� �������� �ٽ� �� �� �����Ƿ� �ٴٷ� �����. 

	while (true)
	{
		bool flag = false;
		for (int i = 0; i < 4; i++)//4�������� 
		{
			direction -= 1;// ������ �������� ������. 
			if (direction < 0) direction += 4;
			int nx = x + dx[direction];
			int ny = y + dy[direction];
			if (Land[nx][ny] == 0)//���� �������� ���� �������� �� �� �ִٸ�
			{
				x = nx; //�̵��� �Ŀ� 
				y = ny;
				flag = true;// �̵��ϴµ� �����ߴٴ� ǥ�ø� ����� 
				Land[nx][ny] = 1;//�湮�� ������ ǥ���Ѵ�. 
				cnt++;
				break;
			}
		}
		if (!flag)//���� �̵����� ���ߴٸ� 
		{
			if (Land[x - dx[direction]][y - dy[direction]] != 0) break;//�������� �̵��غ��µ� �̵��� �� ���ٸ� �״�� �����Ѵ�. 
			else {//���� �̵��� �����ϴٸ� �������� �̵��ϰ� �ٽ� �����Ѵ�. 
				x -= dx[direction];
				y -= dy[direction];
				Land[x - dx[direction]][y - dy[direction]] = 1;//�� ���� �湮 ǥ�����ش�. 
				cnt++;
			}
		}
	}
	cout << cnt << endl;

	return 0;
}