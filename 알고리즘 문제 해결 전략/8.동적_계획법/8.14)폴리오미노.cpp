#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
#include <climits>
#include <string>

using namespace std;
const int MOD = 10000000;
int cache[101][101];
int poly(int n, int first)//n개의 정사각형으로 이루어진, 맨 위 가로줄에 first개의 정사각형을 포함하는 폴리아미노 수를 반환
{
	if (n == first)return 1;//기저사례 n=first
	int& ret = cache[n][first];
	if (ret != -1)return ret;
	ret = 0;
	for (int second = 1; second <= n - first; ++second)//두번째 층 second
	{
		int add = second + first - 1;//이들을 붙일 수 있는 방법
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
