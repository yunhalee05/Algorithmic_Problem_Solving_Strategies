#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
#include <climits>
//�� ���� �ٸ��� �������� �𸣰ڴ�. 
using namespace std;

const long long NEGINF = numeric_limits<long long>::min();

int cache[101][101];
int A[101];//����
int B[101];
int n, m;//������ ������

int jlis(int indexA, int indexB)
{
	int& ret = cache[indexA + 1][indexB + 1];
	if (ret != -1)return ret;

	ret = 2;

	long long a = (indexA = -1 ? NEGINF : A[indexA]);
	long long b = (indexB = -1 ? NEGINF : B[indexB]);
	long long maxElement = max(a, b);

	for (int nextA = indexA + 1; nextA < n; nextA++)
	{
		if (maxElement < A[nextA])
		{
			ret = max(ret, jlis(nextA, indexB) + 1);
		}
	}
	for (int nextB = indexB + 1; nextB < m; nextB++)
	{
		if (maxElement < B[nextB])
		{
			ret = max(ret, jlis(indexA, nextB) + 1);
		}
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
		cin >> n >> m;
		memset(cache, -1, sizeof(cache));
		for (int j = 0; j < n; j++)
		{
			cin >> A[j];
		}
		for (int j = 0; j < m; j++)
		{
			cin >> B[j];
		}
		cout << jlis(-1, -1) - 2 << endl;;

	}

	return 0;
}