#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int cache[101];//수열과 같은 크기의 배열 받는다.
int S[101];//수열
int n;//수열의 사이즈

int list(int start)
{
	int& res = cache[start + 1];//-1부터 시작했으므로  cache는 start+1로 설정
	if (res != -1)
	{
		return res;//값이 이미 저장된 경우는 그 값으로 돌려준다(memoization)
	}
	res = 1;//처음에 무조건 start하나가 들어가므로 기본값은 1일 것이다. 
	for (int i = start + 1; i < n; i++)
	{
		if (S[start] < S[i])//증가수열이므로 지금 값보다 큰 경우 옆에 넣어준다. 
		{
			res = max(res, list(i) + 1);//나올수 있는 결과값이 더 큰것으로 바꿔준다. (길이가 더 큰 수열의 사이즈를 반환)
		}
	}

	return res;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int c;

	cin >> c;//케이스 반복 입력받고 

	for (int i = 0; i < c; i++)//케이스마다 새로운 배열 생성
	{
		memset(cache, -1, sizeof(cache));//처음에 모두 -1로 설정해준다.

		for (int j = 0; j < n; j++)
		{
			cin >> S[i];//배열을 입력받는다.
		}

		cout << list(-1) - 1 << endl;//함수 호출(여기서 -1은 S에는 없는 -1값을 입력받고 실행했으므로 s[-1]의 경우를 제거해주는 것이다. 

	}
}