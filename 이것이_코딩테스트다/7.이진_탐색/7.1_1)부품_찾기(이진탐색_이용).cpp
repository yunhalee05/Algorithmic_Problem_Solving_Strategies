#include <iostream>
#include <vector>
#include <algorithm>


using namespace std;

int n, m;
vector<int> items;
vector<int> order;

int binarySearch(int Left, int Right, int number) {//이진탐색 재귀함수 이용

	if (Left > Right) return 0;//끝까지 갔는데 없으면 0 리턴

	int mid = (Left + Right) / 2;

	if (items[mid] == number) {//찾으면 1리턴
		return 1;
	}
	else if (items[mid] < number) {//범위에 없다면 범위를 다시 정해서 탐색
		binarySearch(mid + 1, Right, number);
	}
	else {
		binarySearch(Left, mid - 1, number);
	}



}
int main() {
	cin >> n;

	for (int i = 0; i < n; i++)//부품목록 입력받기
	{
		int number;
		cin >> number;
		items.push_back(number);
	}
	sort(items.begin(), items.end());

	cin >> m;
	for (int i = 0; i < m; i++)//구매목록 입력받기
	{
		int number;
		cin >> number;
		order.push_back(number);
	}

	for (int i = 0; i < m; i++)//이진탐색 함수를 이용해서 부품이 있으면 Yes, 없으면 No 출력
	{
		if (binarySearch(0, n - 1, order[i]) == 1) cout << "Yes" << " ";
		else cout << "No" << " ";
	}


	return 0;




}