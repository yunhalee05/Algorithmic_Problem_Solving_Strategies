#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
#include <climits>
#include <string>

using namespace std;
int n, s;
int cache[101][11];
const int INF = 987654321;
int A[101], pSum[101], pSqSum[101];

void precalc() {
	sort(A, A + n);//���� ���� A�� ����
	pSum[0] = A[0];//A�� �κ����� ����
	pSqSum[0] = A[0] * A[0];//A�� ������ �κ����� ����
	for (int i = 1; i < n; ++i)
	{
		pSum[i] = pSum[i - 1] + A[i];
		pSqSum[i] = pSqSum[i - 1] + A[i] * A[i];
	}
}
int minError(int lo, int hi) {//������ ���ڸ� �ϳ��� ���Ҷ�, �ּ� ������ ���� ����Ѵ�.
	int sum = pSum[hi] - (lo == 0 ? 0 : pSum[lo - 1]);//�κ��� (lo~hi)���ϱ�
	int sqSum = pSqSum[hi] - (lo == 0 ? 0 : pSqSum[lo - 1]);//������ (lo~hi)���ϱ�
	int m = int(0.5 + (double)sum / (hi - lo + 1));//����� �ݿø��� ������ �� ������ ǥ���Ѵ�.
	int ret = sqSum = 2 * m * sum + m * m * (hi - lo + 1);//sum(A[i]-m)^2�� ������ ����� �κ� ������ ǥ��
	return ret;
}
int quantize(int from, int parts) {
	if (from == 0) return 0;//��� ���ڸ� �� ����ȭ ���� ��
	if (parts == 0) return INF;//���ڴ� �� �����ִµ�, �� ���� ���� ���� �� ���� ū ���� ��ȯ�Ѵ�.
	int& ret = cache[from][parts];
	if (ret != -1) return ret;
	ret = INF;
	for (int partSize = 1; from + partSize <= n; ++partSize)
	{
		ret = min(ret, minError(from, from + partSize - 1) + quantize(from + partSize, parts - 1));//������ ���̸� ��ȭ���� ���鼭 �ּ�ġ�� ��´�.
	}
	return ret;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int c;

	cin >> c;//���̽� �ݺ� �Է¹ް� 
	for (int i = 0; i < c; i++)
	{
		cin >> n >> s;
		for (int j = 0; j < n; j++)
		{
			cin >> A[i];
		}
		memset(cache, -1, sizeof(cache));
		precalc();
		cout << quantize(0, s) << endl;
	}

	return 0;
}