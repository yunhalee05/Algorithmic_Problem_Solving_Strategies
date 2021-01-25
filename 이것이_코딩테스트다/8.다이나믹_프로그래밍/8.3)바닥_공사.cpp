#include <iostream>
#include <vector>
#include <algorithm>


using namespace std;

int d[1001];
int n;

int main() {
	cin >> n;

	d[0] = 0;
	d[1] = 1;
	d[2] = 3;

	//다이나믹프로그래밍(보텀업)
	for (int i = 3; i <= n; i++)
	{
		d[i] = (d[i - 1] + d[i - 2] * 2) % 796796;
	}

	cout << d[n] << endl;

	return 0;

}


