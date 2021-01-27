#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#define INF 1e9


using namespace std;

int n;
int indegree[501];
vector<int> graph;
int times[501];


//다시풀기

int main() {
	vector<int> result(501);

	cin >> n;

	queue<int> q;

	for (int i = 0; i < n; i++)
	{
		if (indegree[i] == 0)
			q.push(i);
	}

	while (!q.empty())
	{
		int now = q.front();
		q.pop();
		for (int i = 0; i < graph[now].size(); i++) {

		}
	}

	return 0;
}
