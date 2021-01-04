#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
#include <climits>
#include <string>

using namespace std;

int skip;//얘를 건너띄고 출력한다.
const int M = 1000000100;//오버플로우를 막기 위해서 이보다 큰 값은 구하지 않는다(k+100)
int bino[201][201];//이항계수(n, m 개의 '-''o'를 뽑을 경우의 수
void calcBino() {//이항계수표를 미리 계산해 놓자
	memset(bino, 0, sizeof(bino));//미리 0으로 초기화 해 놓고
	for (int i = 0; i <= 200; ++i)
	{
		bino[i][0] = bino[i][i] = 1;//총갯수에서 0개를 뽑거나 총갯수만큼 뽑는 경우의 수는 1가지다.
		for (int j = 1; j < i; ++j)//총갯수보다 뽑는 갯수가 작아야 한다. 
		{
			bino[i][j] = min(M, bino[i - 1][j - 1] + bino[i - 1][j]);//오버플로우의 위험 때문에 최댓값보다 큰 값은 구하지 않는다. 이항계수의 공식을 이용해서 이 식을 유추할 수 있다.
		}
	}
}
void generate3(int n, int m, string s) {
	if (skip < 0) return;//뽑는 수가 0보다 작으면 뽑을 수 없음
	if (n == 0 && m == 0) {//기저사례:끝에 도달했다.
		if (skip == 0) cout << s << endl;
		--skip;
		return;
	}
	if (bino[n + m][n] <= skip) {//건너뛸 수가 이항계수보다 크다면 
		skip -= bino[n + m][n];//건너뛸 수를 재설정한다. 그리고 종료해버린다.
		return;
	}
	if (n > 0) generate3(n - 1, m, s + "-");
	if (m > 0) generate3(n, m - 1, s + "o");
}
int main() {

	int n, m, k;
	string s;
	cin >> n >> m >> k;

	skip = k - 1;
	calcBino();

	generate(n, m, s);

	return 0;
}
