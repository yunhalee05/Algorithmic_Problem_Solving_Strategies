#include <iostream>
#include <vector>
#include <algorithm>
#include <set>


using namespace std;

int n, m;
set <int> items;
vector<int> order;
int main() {
	cin >> n;

	for (int i = 0; i < n; i++)
	{
		int number;
		cin >> number;
		items.insert(number);
	}

	cin >> m;
	for (int i = 0; i < m; i++)
	{
		int number;
		cin >> number;
		order.push_back(number);
	}

	for (int i = 0; i < m; i++)
	{
		if (items.find(order[i]) != items.end()) cout << "Yes" << " ";//set함수에 있으면
		else cout << "No" << " ";
	}


	return 0;

}