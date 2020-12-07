#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int cache[101];//������ ���� ũ���� �迭 �޴´�.
int S[101];//����
int n;//������ ������

int list(int start)
{
	int& res = cache[start + 1];//-1���� ���������Ƿ�  cache�� start+1�� ����
	if (res != -1)
	{
		return res;//���� �̹� ����� ���� �� ������ �����ش�(memoization)
	}
	res = 1;//ó���� ������ start�ϳ��� ���Ƿ� �⺻���� 1�� ���̴�. 
	for (int i = start + 1; i < n; i++)
	{
		if (S[start] < S[i])//���������̹Ƿ� ���� ������ ū ��� ���� �־��ش�. 
		{
			res = max(res, list(i) + 1);//���ü� �ִ� ������� �� ū������ �ٲ��ش�. (���̰� �� ū ������ ����� ��ȯ)
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

	cin >> c;//���̽� �ݺ� �Է¹ް� 

	for (int i = 0; i < c; i++)//���̽����� ���ο� �迭 ����
	{
		memset(cache, -1, sizeof(cache));//ó���� ��� -1�� �������ش�.

		for (int j = 0; j < n; j++)
		{
			cin >> S[i];//�迭�� �Է¹޴´�.
		}

		cout << list(-1) - 1 << endl;//�Լ� ȣ��(���⼭ -1�� S���� ���� -1���� �Է¹ް� ���������Ƿ� s[-1]�� ��츦 �������ִ� ���̴�. 

	}
}