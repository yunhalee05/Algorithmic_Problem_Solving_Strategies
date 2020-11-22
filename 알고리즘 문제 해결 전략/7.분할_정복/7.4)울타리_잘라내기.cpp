#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <limits>
#include <cmath>

using namespace std;



int Ractangular(int left, int right, vector<int>& Height)
{
	if (left == right)
	{
		return Height[left];
	}
	int mid = (right + left) / 2;
	int result = max(Ractangular(left, mid, Height), Ractangular(mid + 1, right, Height));
	int low = mid, high = mid + 1;
	int height = min(Height[low], Height[high]);
	result = max(result, height * 2);
	while (left < low || high < right)
	{
		if (high < right && (low == left || Height[low - 1] < Height[high + 1]))
		{
			++high;
			height = min(height, Height[high]);
		}
		else {
			--low;
			height = min(height, Height[low]);
		}
	}
	result = max(result, height * (high - low + 1));
	return result;
}


int main()
{
	int c, n, tmp;
	vector<int>Height;
	cin >> c;

	for (int casenumber = 0; casenumber < c; casenumber++)
	{
		cin >> n;
		for (int i = 0; i < n; i++)
		{
			cin >> tmp;
			Height.push_back(tmp);
		}
	}
	int result = Ractangular(0, n - 1, Height);
	cout << result << endl;
	return 0;
}