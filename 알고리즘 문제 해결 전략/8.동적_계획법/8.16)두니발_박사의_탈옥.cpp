#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
#include <climits>
#include <string>

using namespace std;
int c, n, d, p, num, t, q;
double cache[51][101];//�޸������̼�
int A[51][51], deg[51];//A�� ���� ���� ����, deg�� ���� i�� ����� ������ ����
double search(int here, int days)//days��¥�� here�� ������ ���� �ִٰ� ����, ������ ���� q�� ������ �������� ���Ǻ� Ȯ���� ��ȯ
{
	if (days == d) return (here == q ? 1.0 : 0.0);//������� d���� ���� ���
	double& ret = cache[here][days];
	if (ret > -0.5) return ret;
	ret = 0.0;
	for (int there = 0; there < n; ++there)
	{
		if (A[here][there])//������ �Ǿ� �ִٸ�
			ret += search(there, days + 1) / deg[here];//Ȯ���� �����ش�.
		return ret;
	}
}
int main() {

	cin >> c;
	for (int i = 0; i < c; i++)
	{
		cin >> n >> d >> p;
		for (int j = 0; j < n; j++)
		{
			for (int k = 0; k < n; k++)
			{
				cin >> A[j][k];
				deg[j] += A[j][k];
			}
		}
		cin >> t;
		for (int j = 0; j < t; j++)
		{
			cin >> q;
			cout << search(p, d) << " ";
		}
		cout << endl;
	}
	return 0;
}
