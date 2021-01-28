#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#define INF 1e9


using namespace std;


//���̳��� ���α׷���
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
		//i��° �ķ��� ���� �ʴ� ����� ��(i-1���� �ʹ� ���)�� i��° �ķ��� �ʹ� ����� ��(i-2�� �а� �� ���� i��° �ķ��� �� �� �ִ�.)
		arr[i] = max(arr[i - 1], arr[i - 2] + food[i]);
	}

	cout << arr[n - 1] << endl;

	return 0;

}