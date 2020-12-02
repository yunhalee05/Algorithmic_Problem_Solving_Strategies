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
		return ret;//�̹� ����Ǿ� �ִ� ����� skip(���� ��ȹ��)
	}
	if ((n < name.size() && w < Wild.size()) && (name[n] = '?' || name[n] == Wild[w]))//���ų� ?�� ���� ���� �� �˻�
	{
		return Wildcard(n + 1, w + 1, name, Wild);
	}
	if (w == Wild.size() && n == name.size())//������ �Ѵ� ���� �����ߴٸ� ���̴�.
	{
		return ret = 1;
	}
	if (name[n] == '*')
	{
		if (Wildcard(n + 1, w, name, Wild) || (w < Wild.size() && Wildcard(n, w + 1, name, Wild)))
			return ret = 1;//*�� �ƹ��͵� �������� �ʴ� ����, �ϳ� �������� ��츦 ���ؼ� ������ ������ ������ ���̴�.
	}
	return ret = 0;//�̿��� ���� ��� �������� ģ��.
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
			memset(Catch, -1, sizeof(Catch));//string���� -1�� �ʱ�ȭ ���־�� �Ѵ�.

			cin >> Wild;


			if (Wildcard(0, 0, name, Wild) == 1)//�������̶�� ���� �迭�� �߰�
				answer.push_back(Wild);
		}

		sort(answer.begin(), answer.end());//���̽����� ���ĺ� ����������
		for (int i = 0; i < answer.size(); i++)
		{
			cout << answer[i] << endl;//
		}
	}

}

/* ó���� �ߴ� ��
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
		else if (name[i] == '*')//�̷����̶�� *�� ��� ������ �� �� ���� ����.
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