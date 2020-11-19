#include <iostream>
#include <vector>
#include <string>


using namespace std;

int H, W;
int Shape[20][20] = { 0, };
int num = 0;
int Count = 0;

int Color(int h, int w, int num);

int main()
{
	int c;
	cin >> c;
	vector<int>answer;

	for (int i = 0; i < c; i++)
	{
		Count = 0;

		cin >> H >> W;
		num = 0;

		for (int i = 0; i < H; i++)
		{
			string s;
			cin >> s;

			for (int j = 0; j < W; j++)
			{

				if (s[j] == '#')
				{
					Shape[i][j] = 1;
				}
				else if (s[j] == '.')
				{
					Shape[i][j] = 0;
					num++;
				}
			}
		}

		Count = Color(0, 0, num);

		answer.push_back(Count);

	}

	for (int i = 0; i < c; i++)
	{
		cout << answer[i] << endl;
	}


}

int Color(int h, int w, int num)
{
	if ((num % 3) != 0)//3���� ���������� ������ ����� ������ 0�̴�. 
	{
		Count = 0;
		return Count;
	}

	if (num == 0)//���� ��� ������ ������ ī��Ʈ �����ϰ� ����.
	{
		Count++; return Count;
	}

	if (Shape[h][w] == 1)//�̹� �� �ִ°�쿡�� �������� ����������� �̵��ؼ� �ٽ��Ѵ�. 
	{
		if (w + 1 == W) return Count += Color(h + 1, 0, num);
		else return Count += Color(h, w + 1, num);
	}

	//����� ��쿡 �װ��� ��츦 ����� �����Ѵ�. 
	Shape[h][w] = 1;
	if ((h + 1 < H) && (w + 1 < W))//�̵��� ������ ���� �ȿ� �ִ��� Ȯ��
	{
		if (Shape[h + 1][w + 1] == 0 && Shape[h + 1][w] == 0)//���ڸ��
		{
			Shape[h + 1][w + 1] = 1;
			Shape[h + 1][w] = 1;
			Count += Color(h, w + 1, num - 3);//���������� �̵��ؼ� ����
			Shape[h + 1][w + 1] = 0;
			Shape[h + 1][w] = 0;
		}
		if (Shape[h][w + 1] == 0 && Shape[h + 1][w] == 0)//���� ������ ȸ�����
		{
			Shape[h][w + 1] = 1;
			Shape[w + 1][h] = 1;
			Count += Color(h, w + 1, num - 3);//���������� �̵��ؼ� ����
			Shape[h][w + 1] = 0;
			Shape[h + 1][w] = 0;
		}
		if (Shape[h][w + 1] == 0 && Shape[h + 1][w + 1] == 0)//�� �� ���
		{
			Shape[h][w + 1] = 1;
			Shape[h + 1][w + 1] = 1;
			Count += Color(h, w + 1, num - 3);//���������� �̵��ؼ� ����
			Shape[h][w + 1] = 0;
			Shape[h + 1][w + 1] = 0;
		}
	}
	if (w - 1 >= 0 && h + 1 < H)
	{
		if (Shape[h + 1][w] == 0 && Shape[h][w - 1] == 0)//���� ������ ȸ�����
		{
			Shape[h + 1][w] = 1;
			Shape[h][w - 1] = 1;
			if (w + 1 >= W)
			{
				Count += Color(h + 1, 0, num - 3);
			}
			else { Count += Color(h, w + 1, num - 3); }//���������� �̵��ؼ� ����
			Shape[h + 1][w] = 0;
			Shape[h][w - 1] = 0;

		}
	}
	Shape[h][w] = 0;

	return Count;
}