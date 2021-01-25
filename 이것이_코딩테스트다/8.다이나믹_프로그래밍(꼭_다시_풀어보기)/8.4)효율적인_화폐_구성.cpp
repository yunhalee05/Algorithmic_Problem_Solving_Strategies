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

	//���̳��� ���α׷���(���Ҿ�)
	d[0] = 0;
	for (int i = 0; i < n; i++)//ȭ��������� �˻�
	{
		for (int j = money[i]; j <= m; j++)//ȭ������� ������ ���Ϸ��� ������ ����
		{
			//ȭ������� ����� �Ǵ� ���� 10001���� �ƴ� ���̴�. (i-k���� �����ϴ� ���)
			if (d[j - money[i]] != 10001) {
				//����� ����� ���� ���� �ּڰ� ����ؼ� ����
				d[j] = min(d[j], d[j - money[i]] + 1);
			}
		}
	}


	if (d[m] == 10001)//����� ����� ���� ���
	{
		cout << "-1" << endl;
	}
	else { cout << d[m] << endl; }

	return 0;

}
