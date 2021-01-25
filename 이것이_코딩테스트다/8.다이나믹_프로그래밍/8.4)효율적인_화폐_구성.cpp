#include <iostream>
#include <vector>
#include <algorithm>


using namespace std;


int n, m;
vector<int> money;

int main() {
	cin >> n >> m;
	for (int i = 0; i < n; i++)
	{
		int number;
		cin >> number;
		money.push_back(number);
	}
	vector<int>d(m + 1, 10001);

	//다이나믹 프로그래밍(보텀업)
	d[0] = 0;
	for (int i = 0; i < n; i++)//화폐단위마다 검색
	{
		for (int j = money[i]; j <= m; j++)//화폐단위의 값부터 구하려는 값까지 설정
		{
			//화폐단위로 계산이 되는 값은 10001값이 아닐 것이다. (i-k원이 존재하는 경우)
			if (d[j - money[i]] != 10001) {
				//방법이 생기고 값에 따라서 최솟값 계속해서 갱신
				d[j] = min(d[j], d[j - money[i]] + 1);
			}
		}
	}


	if (d[m] == 10001)//만드는 방법이 없는 경우
	{
		cout << "-1" << endl;
	}
	else { cout << d[m] << endl; }

	return 0;

}
