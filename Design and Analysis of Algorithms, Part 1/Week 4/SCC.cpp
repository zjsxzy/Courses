#include <map>
#include <set>
#include <list>
#include <cmath>
#include <queue>
#include <stack>
#include <bitset>
#include <vector>
#include <cstdio>
#include <string>
#include <sstream>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
#define PB push_back
#define MP make_pair
#define SZ(v) ((int)(v).size())
#define abs(x) ((x) > 0 ? (x) : -(x))
#define FOREACH(e,x) for(__typeof(x.begin()) e=x.begin();e!=x.end();++e)
typedef long long LL;

const int MAXN = 900000;
struct Graph {
	int n, size, depth;
	vector<int> adj[MAXN];
	int low[MAXN], dfn[MAXN], id[MAXN], cnt[MAXN];
	bool vis[MAXN];
	stack<int> S;

	void init(int n) {
		this->n = n;
		for (int i = 0; i <= n; i++)
			adj[i].clear();
		memset(id, 0, sizeof(id));
		memset(vis, 0, sizeof(vis));
		while (!S.empty()) S.pop();
	}

	void addEdge(int u, int v) {
		adj[u].PB(v);
	}

	void Tarjan(int u) {
		dfn[u] = low[u] = depth++;
		S.push(u);
		vis[u] = true;
		for (int i = 0; i < adj[u].size(); i++) {
			int v = adj[u][i];
			if (dfn[v] == -1) {
				Tarjan(v);
				low[u] = min(low[u], low[v]);
			} else if (vis[v]) {
				low[u] = min(low[u], dfn[v]);
			}
		}
		if (low[u] == dfn[u]) {
			size++;
			int v;
			do {
				v = S.top();
				S.pop();
				id[v] = size;
				cnt[size]++;
				vis[v] = false;
			} while (u != v);
		}
	}

	void SCC() {
		memset(dfn, -1, sizeof(dfn));
		memset(cnt, 0, sizeof(cnt));
		size = 0;
		depth = 1;
		for (int i = 0; i < n; i++)
			if (dfn[i] == -1) Tarjan(i);
		printf("%d\n", size);
		sort(cnt, cnt + size + 1);
		reverse(cnt, cnt + size + 1);
		for (int i = 0; i < 5; i++)
			printf("%d,", cnt[i]);
	}

}g;

int main(int argc, char const *argv[])
{
	g.init(900000);
	int a, b;
	while (~scanf("%d%d", &a, &b)) {
		g.addEdge(a, b);
	}
	g.SCC();
	return 0;
}