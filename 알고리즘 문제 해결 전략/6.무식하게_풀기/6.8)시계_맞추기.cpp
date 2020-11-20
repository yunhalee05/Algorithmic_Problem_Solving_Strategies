#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <limits>

using namespace std;

const int linked[10][16] = {
	{1, 1, 1, 0, 0 , 0 , 0 , 0 , 0 , 0 , 0, 0, 0, 0, 0, 0 },
	{0, 0, 0, 1, 0 , 0 , 0 , 1 , 0 , 1 , 0, 1, 0, 0, 0, 0 },
	{0, 0, 0, 0, 1 , 0 , 0 , 0 , 0 , 0 , 1, 0, 0, 0, 1, 1 },
	{1, 0, 0, 0, 1 , 1 , 1 , 1 , 0 , 0 , 0, 0, 0, 0, 0, 0 },
	{0, 0, 0, 0, 0 , 0 , 1 , 1 , 1 , 0 , 1, 0, 1, 0, 0, 0 },
	{1, 0, 1, 0, 0 , 0 , 0 , 0 , 0 , 0 , 0, 0, 0, 0, 1, 1 },
	{0, 0, 0, 1, 0 , 0 , 0 , 0 , 0 , 0 , 0, 0, 0, 0, 1, 1 },
	{0, 0, 0, 0, 1 , 1 , 0 , 1 , 0 , 0 , 0, 0, 0, 0, 1, 1 },
	{0, 1, 1, 1, 1 , 1 , 0 , 0 , 0 , 0 , 0, 0, 0, 0, 0, 0 },
	{0, 0, 0, 1, 1 , 1 , 0 , 0 , 0 , 1 , 0, 0, 0, 1, 0, 0 },
};


bool areAligned(vector<int>& Clock)
{
	for (int i = 0; i < 16; i++)
	{
		if (Clock[i] != 12)
		{
			return false;
		}
	}

	return true;

}
void Push(vector<int>& Clock, int s)
{
	for (int i = 0; i < 16; i++)
	{
		if (linked[s][i] == 1)
		{
			Clock[i] += 3;
			if (Clock[i] > 12) Clock[i] -= 12;
		}
	}
}
int Solve(vector<int>& Clock, int s)
{
	if (s == 10)
	{
		return areAligned(Clock) ? 0 : 2147000000;
	}
	int result = 2147000000;
	for (int count = 0; count < 4; count++)
	{
		result = min(result, count + Solve(Clock, s + 1));//0부터라서 안한 것 까지 포함.
		Push(Clock, s);
	}//4번 돌고 끝나기 때문에 원래자리라서 따로 안해줘도 된다.
	return result;
}
int main()
{
	int c;
	cin >> c;
	vector<int> Clock(16);


	for (int j = 0; j < c; j++)
	{
		for (int i = 0; i < 16; i++)
		{
			cin >> Clock[i];
		}
		int result = Solve(Clock, 0);
		if (result > 9999)
		{
			cout << "-1" << endl;
		}
		else
		{
			cout << result << endl;
		}

	}

	return 0;
}