#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
#include <climits>
#include <string>

using namespace std;

const int MAX = 2000000000 + 1;//k��°���� 1�� �� ū��
int n;
int cacheLen[501], cacheCnt[501], S[500];
int lis(int start) {//S[start]���� �����ϴ� ���� �κ� ���� �� �ִ� ���̸� ��ȯ

	int& ret = cacheLen[start + 1];//�޸������̼�
	if (ret != -1) return ret;
	ret = 1; //�׻� S[start]�� �ֱ� ������ ���� ���̴� 1
	for (int next = start + 1; next < n; ++next)
	{
		if (start == -1 || S[start] < S[next])
			ret = max(ret, lis(next) + 1);
		return ret;
	}
}
int count(int start) {//S[start]���� �����ϴ� �ִ� ���� �κ� ������ ���� ��ȯ
	if (lis(start == 1)) return 1;//LIS���̰� 1�� ���

	int& ret = cacheCnt[start + 1];//�޸������̼�
	if (ret != -1) return ret;

	ret = 0;

	for (int next = start + 1; next < n; ++next)
	{
		if ((start == -1 || S[start] < S[next]) && lis(start) == lis(next) + 1)
			ret = min<long long>(MAX, (long long)ret + count(next));
	}
	return ret;
}
void reconstruct(int start, int skip, vector<int>& Lis) {//S[start]���� �����ϴ� LIS�� ���������� skip�� �ǳʶ� ������ lis �� �����Ѵ�.
	if (start != -1) Lis.push_back(S[start]);//S[start]�� �׻� LIS�� ���Եȴ�
	vector<pair<int, int>> followers;//�ڿ� �� �� �ִ� ���ڵ�� ��ġ�� ����� �����.(����, ������ ��ġ)
	for (int next = start + 1; next < n; ++next)
		if ((start == -1 || S[start] < S[next]) && lis(start) == lis(next) + 1)//���������̸� 
			followers.push_back(make_pair(S[next], next));
	sort(followers.begin(), followers.end());
	for (int i = 0; i < followers.size(); ++i)
	{
		int idx = followers[i].second;
		int cnt = count(idx);
		if (cnt <= skip)//����� �ִ� ������ skip ���� �۴ٸ� ����ģ��.
			skip -= cnt;
		else {
			reconstruct(idx, skip, Lis);
			break;
		}
	}
}
int main() {

	int c;
	cin >> c;

	for (int i = 0; i < c; i++)
	{
		int k, n;
		cin >> n >> k;
		for (int j = 0; j < n; j++)
		{
			cin >> S[j];
		}
		memset(cacheCnt, -1, sizeof(cacheCnt));
		memset(cacheLen, -1, sizeof(cacheLen));
		cout << lis(-1) - 1 << endl;

		vector<int> Lis;
		reconstruct(-1, k - 1, Lis);
		for (int j = 0; j < Lis.size(); j++)
		{
			cout << Lis[j] << " ";
		}
		cout << endl;
	}
	return 0;
}
