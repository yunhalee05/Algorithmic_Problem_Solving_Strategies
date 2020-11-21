#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <limits>
#include <cmath>

using namespace std;


/*  수가 너무 많아져서 이 방법으로는 안된다
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
string reverse(string::iterator& it)//문자열로 바로 반환하자
{
	char head = *it;//시작할때는 항상 x로 시작할 것이다. 
	++it;
	if (head == 'b' || head == 'w')
	{
		return string(1, head);//그대로 반환해주고 뒤집어줄거다. 
	}
	string upperLeft = reverse(it);//각각위치의 문자들을 받고 뒤집는다. 
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