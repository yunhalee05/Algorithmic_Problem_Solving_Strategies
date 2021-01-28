#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#define INF 1e9


using namespace std;


//다이나믹 프로그래밍
int arr[101];
vector<int> food;
int n;


int main() {

	cin >> n;
	for (int i = 0; i < n; i++)
	{
		int k;
		cin >> k;
		food.push_back(k);
	}


	arr[0] = food[0];
	arr[1] = food[1];

	for (int i = 2; i < food.size(); i++)
	{
		//i번째 식량을 털지 않는 경우의 수(i-1까지 터는 경우)와 i번째 식량을 터는 경우의 수(i-2를 털고 난 다음 i번째 식량을 털 수 있다.)
		arr[i] = max(arr[i - 1], arr[i - 2] + food[i]);
	}

	cout << arr[n - 1] << endl;

	return 0;

}