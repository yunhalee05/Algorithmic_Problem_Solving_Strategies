#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
#include <climits>
#include <string>

using namespace std;

const int MAX = 2000000000 + 1;//k번째보다 1개 더 큰수
int n;
int cacheLen[501], cacheCnt[501], S[500];
int lis(int start) {//S[start]에서 시작하는 증가 부분 수열 중 최대 길이를 반환

	int& ret = cacheLen[start + 1];//메모이제이션
	if (ret != -1) return ret;
	ret = 1; //항상 S[start]는 있기 때문에 최저 길이는 1
	for (int next = start + 1; next < n; ++next)
	{
		if (start == -1 || S[start] < S[next])
			ret = max(ret, lis(next) + 1);
		return ret;
	}
}
int count(int start) {//S[start]에서 시작하는 최대 증가 부분 수열의 수를 반환
	if (lis(start == 1)) return 1;//LIS길이가 1인 경우

	int& ret = cacheCnt[start + 1];//메모이제이션
	if (ret != -1) return ret;

	ret = 0;

	for (int next = start + 1; next < n; ++next)
	{
		if ((start == -1 || S[start] < S[next]) && lis(start) == lis(next) + 1)
			ret = min<long long>(MAX, (long long)ret + count(next));
	}
	return ret;
}
void reconstruct(int start, int skip, vector<int>& Lis) {//S[start]에서 시작하는 LIS중 사전순으로 skip개 건너띈 수열을 lis 에 저장한다.
	if (start != -1) Lis.push_back(S[start]);//S[start]는 항상 LIS에 포함된다
	vector<pair<int, int>> followers;//뒤에 올 수 있는 숫자들과 위치의 목록을 만든다.(숫자, 숫자의 위치)
	for (int next = start + 1; next < n; ++next)
		if ((start == -1 || S[start] < S[next]) && lis(start) == lis(next) + 1)//증가수열이면 
			followers.push_back(make_pair(S[next], next));
	sort(followers.begin(), followers.end());
	for (int i = 0; i < followers.size(); ++i)
	{
		int idx = followers[i].second;
		int cnt = count(idx);
		if (cnt <= skip)//만들수 있는 갯수가 skip 보다 작다면 지나친다.
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
