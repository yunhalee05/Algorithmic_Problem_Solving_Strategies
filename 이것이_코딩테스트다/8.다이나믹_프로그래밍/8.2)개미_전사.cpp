#include <iostream>
#include <vector>
#include <algorithm>


using namespace std;


int n;
vector<int> food;
int d[101];


int main() {
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		int k;
		cin >> k;

		food.push_back(k);
	}

	d[0] = food[0];
	d[1] = max(food[0], food[1]);

	//다이나믹 프로그래밍 (보텀업)
	for (int i = 2; i < food.size(); i++)
	{
		d[i] = max(d[i - 1], d[i - 2] + food[i]);
	}

	cout << d[n - 1] << endl;

}