#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
#include <climits>
#include <string>

using namespace std;
int c, n, d, p, num, t, q;
double cache[51][101];//메모이제이션
int A[51][51], deg[51];//A는 마을 연결 여부, deg는 마을 i와 연결된 마을의 갯수
double search(int here, int days)//days날짜에 here번 마을에 숨어 있다고 가정, 마지막 날에 q번 마을에 숨어있을 조건부 확률을 반환
{
	if (days == d) return (here == q ? 1.0 : 0.0);//기저사례 d일이 지난 경우
	double& ret = cache[here][days];
	if (ret > -0.5) return ret;
	ret = 0.0;
	for (int there = 0; there < n; ++there)
	{
		if (A[here][there])//연결이 되어 있다면
			ret += search(there, days + 1) / deg[here];//확률을 더해준다.
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
