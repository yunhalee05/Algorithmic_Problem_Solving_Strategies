#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
#include <climits>
#include <string>

using namespace std;

const int INF = 987654321;
string N;
int cache[10002]; //10000자리 이하 자연수

int classify(int a, int b)
{
	string M = N.substr(a, b - a + 1); //N에서 a부터 b-a+1자리를 따로 빼놓는다. 

	if (M == string(M.size(), M[0])) return 1; //첫글자와 같은 문자로만 이루어진 문자열이면 난이도 1

	bool progressive = true;
	for (int i = 0; i < M.size() - 1; ++i)
	{
		if (M[i + 1] - M[i] != M[1] - M[0]) progressive = false;
	}
	if (progressive == true && abs(M[1] - M[0]) == 1) return 2;//차이값이 모두 같고, 그 차이가 1이면(등차수열이면) 난이도 2

	bool alternating = true;
	for (int i = 0; i < M.size(); ++i)
	{
		if (M[i] != M[i % 2]) alternating = false;
	}
	if (alternating) return 4; //두수가 계속해서 번갈아 나타난다면 난이도는 4

	if (progressive) return 5; //공차가 1이아닌 등차수열의 난이도는 5

	return 10;// 그외에는 난이도 10

}

int memorize(int begin)
{
	if (begin == N.size())return 0;//기저 사례의 끝에 도달했을 경우
	int& ret = cache[begin];
	if (ret != -1) return ret;//이미 저장되어 있다면 그 값을 리턴한다. 
	ret = INF;
	for (int L = 3; L <= 5; ++L)//3~5자리로 나눈다.
		if (begin + L <= N.size())
		{
			ret = min(ret, memorize(begin + L) + classify(begin, begin + L - 1));//나눈 값중에서 제일 작은 최소 난이도를 리턴한다. 
		}
	return ret;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int c;

	cin >> c;//케이스 반복 입력받고 
	for (int i = 0; i < c; i++)
	{
		cin >> N;
		memset(cache, -1, sizeof(cache));
		cout << memorize(0) << endl;
	}

	return 0;
}