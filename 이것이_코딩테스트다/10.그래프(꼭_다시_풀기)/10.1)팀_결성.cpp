#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#define INF 1e9


using namespace std;

int n, m;
int parent[100000];

int find_parent(int parent[100000], int x) {
	if (parent[x] != x) {
		parent[x] = find_parent(parent, parent[x]);
	}
	return parent[x];
}

void union_parent(int parent[100000], int a, int b) {
	a = find_parent(parent, a);
	b = find_parent(parent, b);
	if (a < b) parent[b] = a;
	else parent[a] = b;
}
int main() {

	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		parent[i] = i;
	}
	for (int i = 0; i < m; i++) {

		int num, a, b;
		cin >> num >> a >> b;
		if (num == 0) {
			union_parent(parent, a, b);
		}
		else if (num == 1) {
			if (find_parent(parent, a) == find_parent(parent, b)) cout << "YES" << endl;
			else cout << "NO" << endl;
		}
	}

	return 0;


}