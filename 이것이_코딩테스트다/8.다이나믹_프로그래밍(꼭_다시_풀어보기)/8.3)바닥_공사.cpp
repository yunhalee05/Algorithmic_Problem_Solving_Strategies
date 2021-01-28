#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#define INF 1e9


using namespace std;

int d[1001];
int n;

int main() {
	cin >> n;

	d[1] = 1;
	d[2] = 3;
	for (int i = 3; i < n + 1; i++)
	{
		//i-1���� ä���� �ִ� ��� 1ĭ�� ä��� ����� 1�����̰�, i-2���� ä���� �ִ� ��� ������ 2ĭ�� ä��� ����� 2���� �̴�. 
		d[i] = (d[i - 1] + 2 * d[i - 2]) % 796796;
	}

	cout << d[n] << endl;


	return 0;


}