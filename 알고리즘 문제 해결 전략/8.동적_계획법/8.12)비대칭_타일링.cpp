#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
#include <climits>
#include <string>

using namespace std;
const int MOD = 1000000007;
int cache[101];

int tiling(int width)//���ΰ� width�� �簢���� ä��� ����� ����
{
	if (width <= 1)return 1;//������� width�� 1 ���� �϶�
	int& ret = cache[width];
	if (ret != -1)return ret;
	return ret = (tiling(width - 2) + tiling(width - 1)) % MOD;//�����ٷ� ���̴� ���, �����ٷ� ���̴� ����� ���� ���Ѵ�.
}
int asymmetric(int width)//���Ī�� ���ΰ� width�� �簢���� ä��� ����� ���� 
{
	if (width % 2 == 1)//���̰� Ȧ���� ���
		return (tiling(width) - tiling(width / 2) + MOD) % MOD;//��ü ����� ������ ��� ����Ÿ���� �ΰ� ������ ��Ī�� ��츦 ���ش�.
	int ret = tiling(width);//���̰� ¦���� ��ü ����� ��
	ret = (ret - tiling(width / 2) + MOD) % MOD;//���̰� ¦���̰� ��� Ÿ���� ���� ����� ��(������ ���� ���̸� ä��� ����� ���� ���ؼ� ���� �ȴ�)
	ret = (ret - tiling(width / 2 - 1) + MOD) % MOD;//���̰� ¦���̰� ��� Ÿ���� �ִ� ���(������ ���� ���ο��� 1���� ���� (��� Ÿ���� �����Ƿ�) ������ ���̸� ä��� ����� ���� ���ؼ� ����)
	return ret;
}
int main() {
	int c, n;
	cin >> c;
	for (int i = 0; i < c; i++)
	{
		cin >> n;
		cout << asymmetric(n) << endl;
	}
	return 0;
}
