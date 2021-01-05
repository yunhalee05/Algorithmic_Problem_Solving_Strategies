#include <iostream>

using namespace std;

int main() {
	int n, cnt = 0, money[4] = { 500, 100, 50, 10 };

	cin >> n;

	for (int i = 0; i < 4; i++)
	{
		if (n == 0) break;
		cnt += n / money[i];
		n %= money[i];
	}

	cout << cnt << endl;
	return 0;
}