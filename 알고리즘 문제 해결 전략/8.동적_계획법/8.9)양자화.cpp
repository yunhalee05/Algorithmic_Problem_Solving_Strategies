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
	sort(A, A + n);//받은 수열 A를 정렬
	pSum[0] = A[0];//A의 부분합을 저장
	pSqSum[0] = A[0] * A[0];//A의 제곱의 부분합을 저장
	for (int i = 1; i < n; ++i)
	{
		pSum[i] = pSum[i - 1] + A[i];
		pSqSum[i] = pSqSum[i - 1] + A[i] * A[i];
	}
}
int minError(int lo, int hi) {//구간의 숫자를 하나로 정할때, 최소 오차의 합을 계산한다.
	int sum = pSum[hi] - (lo == 0 ? 0 : pSum[lo - 1]);//부분합 (lo~hi)구하기
	int sqSum = pSqSum[hi] - (lo == 0 ? 0 : pSqSum[lo - 1]);//제곱합 (lo~hi)구하기
	int m = int(0.5 + (double)sum / (hi - lo + 1));//평균을 반올림한 값으로 이 수들을 표현한다.
	int ret = sqSum = 2 * m * sum + m * m * (hi - lo + 1);//sum(A[i]-m)^2를 전개한 결과를 부분 합으로 표현
	return ret;
}
int quantize(int from, int parts) {
	if (from == 0) return 0;//모든 숫자를 다 양자화 했을 때
	if (parts == 0) return INF;//숫자는 더 남아있는데, 더 묶을 수가 없을 때 아주 큰 값을 반환한다.
	int& ret = cache[from][parts];
	if (ret != -1) return ret;
	ret = INF;
	for (int partSize = 1; from + partSize <= n; ++partSize)
	{
		ret = min(ret, minError(from, from + partSize - 1) + quantize(from + partSize, parts - 1));//조각의 길이를 변화시켜 가면서 최소치를 얻는다.
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