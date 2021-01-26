#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#define INF 1e9


using namespace std;


int n, m, x, k;
int graph[101][101];


int main() {

	cin >> n >> m;

	for (int i = 0; i < 101; i++)
	{
		fill(graph[i], graph[i] + 101, INF);
	}
	for (int i = 1; i < n + 1; i++) {
		for (int j = 1; j < n + 1; j++) {
			if (i == j) graph[i][j] = 0;
		}
	}
	for (int i = 1; i <= m; i++) {
		int a, b;
		cin >> a >> b;
		graph[a][b] = 1;
		graph[b][a] = 1;
	}

	cin >> x >> k;

	for (int k = 1; k < n + 1; k++)
	{
		for (int a = 1; a < n + 1; a++)
		{
			for (int b = 1; b < n + 1; b++) {
				graph[a][b] = min(graph[a][b], graph[a][k] + graph[k][b]);
			}
		}
	}

	int distance = graph[1][k] + graph[k][x];

	if (distance >= INF) cout << "-1";
	else cout << distance << endl;

	return 0;
}
