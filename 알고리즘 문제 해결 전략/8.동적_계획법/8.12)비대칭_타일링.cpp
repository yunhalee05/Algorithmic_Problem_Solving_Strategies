#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
#include <climits>
#include <string>

using namespace std;
const int MOD = 1000000007;
int cache[101];

int tiling(int width)//가로가 width인 사각형을 채우는 방법의 갯수
{
	if (width <= 1)return 1;//기저사례 width가 1 이하 일때
	int& ret = cache[width];
	if (ret != -1)return ret;
	return ret = (tiling(width - 2) + tiling(width - 1)) % MOD;//세로줄로 덮이는 경우, 가로줄로 덮이는 경우의 수를 합한다.
}
int asymmetric(int width)//비대칭인 가로가 width인 사각형을 채우는 방법의 갯수 
{
	if (width % 2 == 1)//넓이가 홀수인 경우
		return (tiling(width) - tiling(width / 2) + MOD) % MOD;//전체 경우의 수에서 가운데 세로타일을 두고 양쪽이 대칭인 경우를 빼준다.
	int ret = tiling(width);//넓이가 짝수인 전체 경우의 수
	ret = (ret - tiling(width / 2) + MOD) % MOD;//넓이가 짝수이고 가운데 타일이 없는 경우의 수(반으로 나눈 넓이를 채우는 경우의 수만 구해서 빼면 된다)
	ret = (ret - tiling(width / 2 - 1) + MOD) % MOD;//넓이가 짝수이고 가운데 타일이 있는 경우(반으로 나눈 가로에서 1개를 빼고 (가운데 타일이 있으므로) 나머지 넓이를 채우는 경우의 수를 구해서 뺀다)
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
