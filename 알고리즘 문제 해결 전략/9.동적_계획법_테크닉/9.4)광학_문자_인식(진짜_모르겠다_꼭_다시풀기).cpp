#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
#include <climits>
#include <string>

using namespace std;
vector<string> word;
vector<float> percentage;

int main() {
	int m, q;
	float p;
	string alpha;

	cin >> m >> q;
	for (int i = 0; i < m; i++)
	{
		cin >> alpha;
		word.push_back(alpha);
	}
	for (int i = 0; i < m; i++)
	{
		cin >> p;
		percentage.push_back(p);
	}

	return 0;
}