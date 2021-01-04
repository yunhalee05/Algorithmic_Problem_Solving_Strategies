#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
#include <climits>
#include <string>

using namespace std;

int skip;//�긦 �ǳʶ�� ����Ѵ�.
const int M = 1000000100;//�����÷ο츦 ���� ���ؼ� �̺��� ū ���� ������ �ʴ´�(k+100)
int bino[201][201];//���װ��(n, m ���� '-''o'�� ���� ����� ��
void calcBino() {//���װ��ǥ�� �̸� ����� ����
	memset(bino, 0, sizeof(bino));//�̸� 0���� �ʱ�ȭ �� ����
	for (int i = 0; i <= 200; ++i)
	{
		bino[i][0] = bino[i][i] = 1;//�Ѱ������� 0���� �̰ų� �Ѱ�����ŭ �̴� ����� ���� 1������.
		for (int j = 1; j < i; ++j)//�Ѱ������� �̴� ������ �۾ƾ� �Ѵ�. 
		{
			bino[i][j] = min(M, bino[i - 1][j - 1] + bino[i - 1][j]);//�����÷ο��� ���� ������ �ִ񰪺��� ū ���� ������ �ʴ´�. ���װ���� ������ �̿��ؼ� �� ���� ������ �� �ִ�.
		}
	}
}
void generate3(int n, int m, string s) {
	if (skip < 0) return;//�̴� ���� 0���� ������ ���� �� ����
	if (n == 0 && m == 0) {//�������:���� �����ߴ�.
		if (skip == 0) cout << s << endl;
		--skip;
		return;
	}
	if (bino[n + m][n] <= skip) {//�ǳʶ� ���� ���װ������ ũ�ٸ� 
		skip -= bino[n + m][n];//�ǳʶ� ���� �缳���Ѵ�. �׸��� �����ع�����.
		return;
	}
	if (n > 0) generate3(n - 1, m, s + "-");
	if (m > 0) generate3(n, m - 1, s + "o");
}
int main() {

	int n, m, k;
	string s;
	cin >> n >> m >> k;

	skip = k - 1;
	calcBino();

	generate(n, m, s);

	return 0;
}
