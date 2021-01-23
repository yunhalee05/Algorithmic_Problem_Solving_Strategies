#include <iostream>
#include <vector>
#include <algorithm>


using namespace std;

int n, k;
vector<int> A;
vector<int> B;

bool compare(int a, int b) {
	return a > b;
}

int main() {
	 
	cin >> n >> k;

	for (int i = 0; i < n; i++)
	{
		int m;
		cin >> m;
		A.push_back(m);
	}
	for (int i = 0; i < n; i++)
	{
		int m;
		cin >> m;
		B.push_back(m);
	}
	//A는 오름차순, B는 내림차순으로 정렬
	sort(A.begin(), A.end());
	sort(B.begin(), B.end(), compare);

	for (int i = 0; i < k; i++)
	{
		if (A[i] < B[i])
			swap(A[i], B[i]);
		else break;
	}


	//수의 합이 int의 범위를 넘어설 수 있으므로 sum은 long long 으로 지정한다. 
	long long sum = 0;
	for (int i = 0; i < n; i++)
	{
		sum += A[i];
	}

	cout << sum << endl;


	return 0;



}

/*
 처음에 푼 방법(맞았다)
using namespace std;

int n, k,sum = 0;
vector<int> A;
vector<int> B;

int main() {

	cin >> n >> k;

	for (int i = 0; i < n; i++)
	{
		int m;
		cin >> m;
		A.push_back(m);
	}
	for (int i = 0; i < n; i++)
	{
		int m;
		cin >> m;
		B.push_back(m);
	}

	while (k > 0)
	{
		sort(A.begin(), A.end());
		sort(B.begin(), B.end());

		int tmp;
		tmp = A[0];
		A[0] = B[n - 1];
		B[n - 1] = tmp;

		k--;
	}

	for (int i = 0; i < n; i++)
	{
		sum += A[i];
	}

	cout << sum << endl;


	return 0;



}
*/