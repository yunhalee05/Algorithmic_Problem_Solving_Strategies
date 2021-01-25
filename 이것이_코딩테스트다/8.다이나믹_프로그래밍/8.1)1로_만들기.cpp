#include <iostream>
#include <vector>
#include <algorithm>


using namespace std;

int x;
int dp[30001] = { 0, };

int main() {

	cin >> x;
	//dp[1]=0이므로 2부터 시작한다. (보텀업)
	for (int i = 2; i <= x; i++)
	{	//현재의 수에서 1을 빼는경우
		dp[i] = dp[i - 1] + 1;
		//현재의 수에서 2으로 나누는 경우
		if (i % 2 == 0) dp[i] = min(dp[i], dp[i / 2] + 1);
		//현재의 수에서 3으로 나누는 경우
		if (i % 3 == 0) dp[i] = min(dp[i], dp[i / 3] + 1);
		//현재의 수에서 5로 나누는 경우
		if (i % 5 == 0) dp[i] = min(dp[i], dp[i / 5] + 1);
	}
	cout << dp[x] << endl;
}



/*
 처음에 했던 방식(실행 안된다)
int X, x, cnt =0;
int dp[30000] = { 0, };

int calculate(int X, int x, int cnt) {
	if (x == 1) {
		dp[X] = cnt;
		return cnt;
	}

	if (dp[x] != 0) {
		cnt += dp[x];
		dp[X] = cnt;
		return cnt;
	}

	if (x % 5 == 0) {
		x /= 5;
		cnt++;
	}
	else if (x % 3 == 0)
	{
		x /= 3;
		cnt++;
	}
	else if (x % 2 == 0) {
		x /= 2;
		cnt++;
	}
	else {
		x -= 1;
		cnt++;
	}
	calculate(X,x, cnt);

	return cnt;
}

int main() {
	cin >> X;
	int x = X;

	cout << calculate(X, x, 0) << endl;

}*/