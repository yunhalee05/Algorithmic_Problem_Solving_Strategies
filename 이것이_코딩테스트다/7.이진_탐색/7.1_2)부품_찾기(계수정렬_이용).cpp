#include <iostream>
#include <vector>
#include <algorithm>


using namespace std;

int n, m;
int items[1000001];
int order[100000];

int main() {
	cin >> n;

	for (int i = 0; i < n; i++)
	{
		int number;
		cin >> number;
		items[number]++;
	}

	cin >> m;
	for (int i = 0; i < m; i++)
	{
		cin >> order[i];
	}

	for (int i = 0; i < m; i++)
	{
		if (items[order[i]] != 0) cout << "Yes" << " ";
		else cout << "No" << " ";
	}


	return 0;

}
