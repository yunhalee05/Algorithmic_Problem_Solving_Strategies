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
int pack(int capacity, int item)//캐리어에 남은 용량이 capacity일 때, item 이후의 물건들을 담아 얻을 수 있는 최대 절박도의 합을 반환
{
	if (item == n)return 0;//더이살 담을 물건이 없을 때
	int& ret = cache[capacity][item];
	if (ret != -1)return ret;
	ret = pack(capacity, item + 1);//물건을 담지 않을 경우
	if (capacity >= volume[item])//물건을 담을 경우
		ret = max(ret, pack(capacity - volume[item], item + 1) + need[item]);
	return ret;
}
void reconstruct(int capacity, int item, vector<string>& picked)
{
	if (item == n) return; //모든 물건을 다 고려했다.
	if (pack(capacity, item) == pack(capacity, item + 1)) {//최대 절박도에 포함하지 않았다면
		reconstruct(capacity, item + 1, picked);
	}
	else
	{
		picked.push_back(name[item]);//최대 절박도에 포함했다면
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