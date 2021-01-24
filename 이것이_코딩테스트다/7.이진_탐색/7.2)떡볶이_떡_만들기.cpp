#include <iostream>
#include <vector>
#include <algorithm>


using namespace std;

int Max = -2147000000;
int n, m;
vector<int> height;

int binarySearch(int Left, int Right, int Max) {//이진탐색
	while (Left <= Right) {
		int sum = 0;
		int mid = (Left + Right) / 2;
		for (int i = 0; i < n; i++)//생산한 떡의 양 계산
		{
			if (height[i] > mid) sum += (height[i] - mid);
		}
		if (sum < m)Right = mid - 1;//주어진 길이보다 생산한 떡의 양이 작다. 
		else {//주어진 길이보다 크거나 같은 떡을 생산할 수 있다. 
			Max = mid;
			Left = mid + 1;
		}
	}

	return Max;
}

int main() {
	cin >> n >> m;
	for (int i = 0; i < n; i++)
	{
		int number;
		cin >> number;
		height.push_back(number);
	}
	sort(height.begin(), height.end());

	cout << binarySearch(0, height[n - 1], Max) << endl;


	return 0;
}