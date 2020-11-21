#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <limits>
#include <cmath>

using namespace std;


/*  ���� �ʹ� �������� �� ������δ� �ȵȴ�
const double MAX = pow(2, 20);
char decompressed[MAX][MAX];

void decompress(string::iterator&it,int y, int x, int size)
{
	char head = *(it++);
	if (head == 'b' || head == 'w')
	{
		for (int dy = 0; dy < size; ++dy)
		{
			for (int dx = 0; dx < size; ++dx)
			{
				decompressed[y + dy][x + dx] = head;
			}
		}
	}
	else
	{
		int half = size / 2;
		decompress(it, y, x, half);
		decompress(it, y, x + half, half);
		decompress(it, y + half, x, half);
		decompress(it, y + half, x + half, half);
	}

}*/
string reverse(string::iterator& it)//���ڿ��� �ٷ� ��ȯ����
{
	char head = *it;//�����Ҷ��� �׻� x�� ������ ���̴�. 
	++it;
	if (head == 'b' || head == 'w')
	{
		return string(1, head);//�״�� ��ȯ���ְ� �������ٰŴ�. 
	}
	string upperLeft = reverse(it);//������ġ�� ���ڵ��� �ް� �����´�. 
	string upperRight = reverse(it);
	string lowerLeft = reverse(it);
	string lowerRight = reverse(it);

	return string("x") + lowerLeft + lowerRight + upperLeft + upperRight;
}
int main()
{
	int c;
	cin >> c;
	for (int i = 0; i < c; c++)
	{
		string s;
		cin >> s;
		string::iterator it = s.begin();

		cout << reverse(it) << endl;
	}
	return 0;
}