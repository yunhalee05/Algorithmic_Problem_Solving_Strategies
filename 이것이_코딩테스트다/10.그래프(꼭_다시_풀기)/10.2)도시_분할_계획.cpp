#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#define INF 1e9


using namespace std;

int n, m, result = 0;
int parent[100001];
vector<pair<int, pair<int, int>>> edges;

int find_parent(int parent[100001], int x) {
	if (parent[x] != x)
		parent[x] = find_parent(parent, parent[x]);
	return parent[x];
}
void union_parent(int parent[100001], int a, int b) {
	a = find_parent(parent, a);
	b = find_parent(parent, b);
	if (a < b) parent[b] = a;
	else parent[a] = b;
}
int main() {

	cin >> n >> m;

	for (int i = 0; i < n; i++)
	{
		parent[i] = i;
	}
	for (int i = 0; i < m; i++) {
		int a, b, cost;
		cin >> a >> b >> cost;
		edges.push_back({ cost,{a,b} });
	}

	sort(edges.begin(), edges.end());

	int last = 0;

	for (int i = 0; i < edges.size(); i++)
	{
		int cost = edges[i].first;
		int a = edges[i].second.first;
		int b = edges[i].second.second;

		if (find_parent(parent, a) != find_parent(parent, b))
		{
			union_parent(parent, a, b);
			result += cost;
			last = cost;
		}

	}

	cout << result - last << endl;

	return 0;
}