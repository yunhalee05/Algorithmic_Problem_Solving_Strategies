#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
#include <climits>
#include <string>

using namespace std;

const int INF = 987654321;
string N;
int cache[10002]; //10000�ڸ� ���� �ڿ���

int classify(int a, int b)
{
	string M = N.substr(a, b - a + 1); //N���� a���� b-a+1�ڸ��� ���� �����´�. 

	if (M == string(M.size(), M[0])) return 1; //ù���ڿ� ���� ���ڷθ� �̷���� ���ڿ��̸� ���̵� 1

	bool progressive = true;
	for (int i = 0; i < M.size() - 1; ++i)
	{
		if (M[i + 1] - M[i] != M[1] - M[0]) progressive = false;
	}
	if (progressive == true && abs(M[1] - M[0]) == 1) return 2;//���̰��� ��� ����, �� ���̰� 1�̸�(���������̸�) ���̵� 2

	bool alternating = true;
	for (int i = 0; i < M.size(); ++i)
	{
		if (M[i] != M[i % 2]) alternating = false;
	}
	if (alternating) return 4; //�μ��� ����ؼ� ������ ��Ÿ���ٸ� ���̵��� 4

	if (progressive) return 5; //������ 1�̾ƴ� ���������� ���̵��� 5

	return 10;// �׿ܿ��� ���̵� 10

}

int memorize(int begin)
{
	if (begin == N.size())return 0;//���� ����� ���� �������� ���
	int& ret = cache[begin];
	if (ret != -1) return ret;//�̹� ����Ǿ� �ִٸ� �� ���� �����Ѵ�. 
	ret = INF;
	for (int L = 3; L <= 5; ++L)//3~5�ڸ��� ������.
		if (begin + L <= N.size())
		{
			ret = min(ret, memorize(begin + L) + classify(begin, begin + L - 1));//���� ���߿��� ���� ���� �ּ� ���̵��� �����Ѵ�. 
		}
	return ret;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int c;

	cin >> c;//���̽� �ݺ� �Է¹ް� 
	for (int i = 0; i < c; i++)
	{
		cin >> N;
		memset(cache, -1, sizeof(cache));
		cout << memorize(0) << endl;
	}

	return 0;
}