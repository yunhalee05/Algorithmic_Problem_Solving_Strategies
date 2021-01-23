#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool compare(int a, int b) {
	return a > b;
}

int main() {


	int n;
	cin >> n;

	vector <int> arr;

	for (int i = 0; i < n; i++)
	{
		int m;
		cin >> m;
		arr.push_back(m);
	}

	sort(arr.begin(), arr.end(), compare);

	for (int i = 0; i < n; i++)
	{
		cout << arr[i] << " ";
	}

	return 0;

}

