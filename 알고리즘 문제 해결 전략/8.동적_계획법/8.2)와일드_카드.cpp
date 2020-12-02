#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int Catch[101][101] = { -1 };

int Wildcard(int n, int w, string& name, string& Wild)
{
	int& ret = Catch[n][w];
	if (ret != -1)
	{
		return ret;//이미 저장되어 있는 경우라면 skip(동적 계획법)
	}
	if ((n < name.size() && w < Wild.size()) && (name[n] = '?' || name[n] == Wild[w]))//같거나 ?일 때는 다음 것 검사
	{
		return Wildcard(n + 1, w + 1, name, Wild);
	}
	if (w == Wild.size() && n == name.size())//무사히 둘다 끝에 도달했다면 참이다.
	{
		return ret = 1;
	}
	if (name[n] == '*')
	{
		if (Wildcard(n + 1, w, name, Wild) || (w < Wild.size() && Wildcard(n, w + 1, name, Wild)))
			return ret = 1;//*가 아무것도 대응하지 않는 경우와, 하나 대응했을 경우를 비교해서 가능한 경우수가 나오면 참이다.
	}
	return ret = 0;//이외의 경우는 모두 거짓으로 친다.
}
int main()
{
	int c, num;
	cin >> c;
	string name, Wild;


	for (int i = 0; i < c; i++)
	{
		cin >> name >> num;

		vector<string> answer;

		for (int j = 0; j < num; j++)
		{
			memset(Catch, -1, sizeof(Catch));//string마다 -1로 초기화 해주어야 한다.

			cin >> Wild;


			if (Wildcard(0, 0, name, Wild) == 1)//만약참이라면 정답 배열에 추가
				answer.push_back(Wild);
		}

		sort(answer.begin(), answer.end());//케이스마다 알파벳 순서로정렬
		for (int i = 0; i < answer.size(); i++)
		{
			cout << answer[i] << endl;//
		}
	}

}

/* 처음에 했던 답
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;
void Wildcard(string &name, string &wild,vector<string>&answer)
{
	bool flag = true;
	for (int i = 0; i < name.size(); i++)
	{
		if (name[i] == '?')
		{
			continue;
		}
		else if (name[i] !='*'&&name[i]!='?')
		{
			if (name[i] != wild[i])
			{
				flag = false;
				break;
			}
		}
		else if (name[i] == '*')//이런식이라면 *가 어디에 대응할 지 알 수가 없다.
		{
			continue;
		}
	}
	if (flag == true)
	{
		answer.push_back(wild);
	}
}
int main()
{
	int c,n;
	cin >> c;
	string name,wild;
	vector<string> answer;


	for (int i = 0; i < c; i++)
	{
		cin >> name>>n;
		for (int j = 0; j < n; j++)
		{
			cin >> wild;
			Wildcard(name, wild,answer);
		}
		sort(answer.begin(), answer.end());
		for (int i = 0; i < answer.size(); i++)
		{
			cout << answer[i] << endl;
		}
	}

}*/