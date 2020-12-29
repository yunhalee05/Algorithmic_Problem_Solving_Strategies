#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
#include <climits>
#include <string>

using namespace std;
int n, capacity;
int volume[100], need[100];
int cache[1001][100];
string name[100];
int pack(int capacity, int item)//ĳ��� ���� �뷮�� capacity�� ��, item ������ ���ǵ��� ��� ���� �� �ִ� �ִ� ���ڵ��� ���� ��ȯ
{
	if (item == n)return 0;//���̻� ���� ������ ���� ��
	int& ret = cache[capacity][item];
	if (ret != -1)return ret;
	ret = pack(capacity, item + 1);//������ ���� ���� ���
	if (capacity >= volume[item])//������ ���� ���
		ret = max(ret, pack(capacity - volume[item], item + 1) + need[item]);
	return ret;
}
void reconstruct(int capacity, int item, vector<string>& picked)
{
	if (item == n) return; //��� ������ �� ����ߴ�.
	if (pack(capacity, item) == pack(capacity, item + 1)) {//�ִ� ���ڵ��� �������� �ʾҴٸ�
		reconstruct(capacity, item + 1, picked);
	}
	else
	{
		picked.push_back(name[item]);//�ִ� ���ڵ��� �����ߴٸ�
		reconstruct(capacity - volume[item], item + 1, picked);
	}
}
int main() {
	int c;
	cin >> c;
	for (int i = 0; i < c; i++)
	{
		cin >> n >> capacity;
		vector<string> picked;

		for (int j = 0; j < n; j++)
		{
			cin >> name[j] >> volume[j] >> need[j];
		}
		memset(cache, -1, sizeof(cache));
		reconstruct(capacity, 0, picked);
		cout << pack(capacity, 0) << " " << picked.size() << endl;
		for (int j = 0; j < picked.size(); j++)
		{
			cout << picked[j] << endl;
		}
	}
	return 0;
}