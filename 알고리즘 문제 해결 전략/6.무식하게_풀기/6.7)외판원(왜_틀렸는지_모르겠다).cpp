#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <limits>

using namespace std;

vector<bool>visited(8);
double dist[8][8];
double mindist = DBL_MAX;
vector<int>path;
int c, n;


double ShortestPath(double currentlength)
{
	if (path.size() == n)
	{
		currentlength += dist[0][path.back()];

		if (mindist > currentlength)
		{
			mindist = currentlength;
		}
	}

	else
	{

		for (int i = 0; i < n; i++)
		{
			if (visited[i] == false)
			{
				int tmp = path.back();
				path.push_back(i);
				visited[i] = true;
				currentlength += ShortestPath(currentlength + dist[tmp][i]);
				path.pop_back();
				visited[i] = false;
			}
		}
	}
	return mindist;
}

int main()
{
	cin >> c;
	vector<double> answer;
	for (int k = 0; k < c; k++)
	{
		cin >> n;
		for (int i = 0; i < n; i++)
		{
			visited[i] = false;
		}

		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				double temp;
				cin >> temp;
				dist[i][j] = temp;
			}
		}

		path.push_back(0);
		visited[0] = true;

		double answerdist = ShortestPath(0);
		answer.push_back(answerdist);
	}

	for (int i = 0; i < c; i++)
	{
		cout << answer[i] << endl;
	}

	return 0;
}