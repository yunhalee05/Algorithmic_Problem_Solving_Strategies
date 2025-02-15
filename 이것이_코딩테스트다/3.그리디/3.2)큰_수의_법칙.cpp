#include<iostream>
#include <algorithm>

using namespace std;

int main() {

	int n, m, k, number[10000], cnt = 0, answer=0;

	cin >> n >> m >> k;

	for (int i = 0; i < n; i++)
	{
		cin >> number[i];
	}

	sort(number.begin(), number.end(),compare);//내림차순 정렬

	cnt = m / (k + 1) * k + m % (k + 1);
	answer += cnt * number[0];
	answer += (m - cnt) * second;

	/*
	* 처음에 짰던 코드
	1.
	while (m>0)
	{
		if (cnt == k)
		{
			cnt = 0;
			answer += number[1];
			m--;
		}
		else
		{
			cnt++;
			answer += number[0];
			m--;
		}
	}

	2.

	while (1)
	{
		for (int i = 0; i < k; i++)
		{
			if (m == 0) break;
			answer += number[0];
			m--;
		}
		if (m == 0) break;
		answer += number[1];
		m--;
	}

	3.

	int n, m, k,num;
	vector <int> v;

	int main() {

	cin >> n >> m >> k;
	int a;
	for (int i = 0; i < n; i++) {
		cin >> a;
		v.push_back(a);
	}
	num = 0;
	sort(v.begin(), v.end(), greater<int>());

	while (m >= k) {
		num += (v[0] * k + v[1]);
		m -= (k + 1);
	}

	num += (m * v[0]);

	cout << num;

	return 0;

}



	*/

	cout << answer << endl;
	return 0;
}