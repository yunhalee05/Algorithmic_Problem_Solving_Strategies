#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#define INF 1e9


using namespace std;

int d[1001];
int n;

int main() {
	cin >> n;

	d[1] = 1;
	d[2] = 3;
	for (int i = 3; i < n + 1; i++)
	{
		//i-1까지 채워져 있는 경우 1칸을 채우는 방법은 1가지이고, i-2까지 채워져 있는 경우 나머지 2칸을 채우는 방법은 2가지 이다. 
		d[i] = (d[i - 1] + 2 * d[i - 2]) % 796796;
	}

	cout << d[n] << endl;


	return 0;


}