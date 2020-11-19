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
	if ((num % 3) != 0)//3으로 나누어지지 않으면 결과는 어차피 0이다. 
	{
		Count = 0;
		return Count;
	}

	if (num == 0)//남은 흰색 바탕이 없으면 카운트 증가하고 리턴.
	{
		Count++; return Count;
	}

	if (Shape[h][w] == 1)//이미 차 있는경우에는 오른쪽의 흰색바탕으로 이동해서 다시한다. 
	{
		if (w + 1 == W) return Count += Color(h + 1, 0, num);
		else return Count += Color(h, w + 1, num);
	}

	//흰색인 경우에 네가지 경우를 나누어서 진행한다. 
	Shape[h][w] = 1;
	if ((h + 1 < H) && (w + 1 < W))//이동한 범위가 보드 안에 있는지 확인
	{
		if (Shape[h + 1][w + 1] == 0 && Shape[h + 1][w] == 0)//ㄴ자모양
		{
			Shape[h + 1][w + 1] = 1;
			Shape[h + 1][w] = 1;
			Count += Color(h, w + 1, num - 3);//오른쪽으로 이동해서 진행
			Shape[h + 1][w + 1] = 0;
			Shape[h + 1][w] = 0;
		}
		if (Shape[h][w + 1] == 0 && Shape[h + 1][w] == 0)//ㄴ의 오른쪽 회전모양
		{
			Shape[h][w + 1] = 1;
			Shape[w + 1][h] = 1;
			Count += Color(h, w + 1, num - 3);//오른쪽으로 이동해서 진행
			Shape[h][w + 1] = 0;
			Shape[h + 1][w] = 0;
		}
		if (Shape[h][w + 1] == 0 && Shape[h + 1][w + 1] == 0)//ㄱ 자 모양
		{
			Shape[h][w + 1] = 1;
			Shape[h + 1][w + 1] = 1;
			Count += Color(h, w + 1, num - 3);//오른쪽으로 이동해서 진행
			Shape[h][w + 1] = 0;
			Shape[h + 1][w + 1] = 0;
		}
	}
	if (w - 1 >= 0 && h + 1 < H)
	{
		if (Shape[h + 1][w] == 0 && Shape[h][w - 1] == 0)//ㄱ의 오른쪽 회전모양
		{
			Shape[h + 1][w] = 1;
			Shape[h][w - 1] = 1;
			if (w + 1 >= W)
			{
				Count += Color(h + 1, 0, num - 3);
			}
			else { Count += Color(h, w + 1, num - 3); }//오른쪽으로 이동해서 진행
			Shape[h + 1][w] = 0;
			Shape[h][w - 1] = 0;

		}
	}
	Shape[h][w] = 0;

	return Count;
}