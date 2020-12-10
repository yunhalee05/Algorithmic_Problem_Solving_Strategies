#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
#include <climits>
//왜 값이 다르게 나오는지 모르겠다. 
using namespace std;

const long long NEGINF = numeric_limits<long long>::min();

int cache[101][101];
int A[101];//수열
int B[101];
int n, m;//수열의 사이즈

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

	cin >> c;//케이스 반복 입력받고 
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