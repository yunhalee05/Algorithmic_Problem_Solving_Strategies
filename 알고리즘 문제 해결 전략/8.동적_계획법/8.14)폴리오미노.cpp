#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
#include <climits>
#include <string>

using namespace std;
const int MOD = 10000000;
int cache[101][101];
int poly(int n, int first)//n���� ���簢������ �̷����, �� �� �����ٿ� first���� ���簢���� �����ϴ� �����ƹ̳� ���� ��ȯ
{
	if (n == first)return 1;//������� n=first
	int& ret = cache[n][first];
	if (ret != -1)return ret;
	ret = 0;
	for (int second = 1; second <= n - first; ++second)//�ι�° �� second
	{
		int add = second + first - 1;//�̵��� ���� �� �ִ� ���
		add *= poly(n - first, second);
		add %= MOD;
		ret += add;
		ret %= MOD;
	}
	return ret;

}

int main() {
	int c, n, sum;
	cin >> c;
	for (int i = 0; i < c; i++)
	{
		cin >> n;
		for (int j = 1; j <= n; j++)
		{
			sum += poly(n, j);
			sum %= MOD;
		}
		cout << sum << endl;
	}
	return 0;
}
