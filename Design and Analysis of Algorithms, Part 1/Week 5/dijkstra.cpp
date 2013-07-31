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

const int inf = 1000000;
const int maxn = 205;
const int maxm = 40005;
/*
 * SPFA
 */
struct Edge {
	int v, next, w;
};
struct Graph {

	int N, M;
	Edge edge[maxm * 2];
	int num, Head[maxn];
	int dis[maxn], vis[maxn];

	Graph() {}

	void init(int N) {
		this->N = N;
		num = 0;
		memset(Head, -1, sizeof(Head));
	}

	void addEdge(int u, int v, int w) {
		cout << u << " " << v << " " << w << endl;
		edge[num].v = v;
		edge[num].w = w;
		edge[num].next = Head[u];
		Head[u] = num++;
	}

	int SPFA(int st) {
		for (int i = 1; i <= N; i++) {
			dis[i] = inf;
			vis[i] = false;
		}
		vis[st] = true;
		dis[st] = 0;
		queue<int> Q;
		Q.push(st);
		while (!Q.empty()) {
			int u = Q.front();
			Q.pop();
			vis[u] = false;
			for (int i = Head[u]; i != -1; i = edge[i].next) {
				int v = edge[i].v;
				if (dis[u] + edge[i].w < dis[v]) {
					dis[v] = dis[u] + edge[i].w;
					if (!vis[v]) {
						vis[v] = true;
						Q.push(v);
					}
				}
			}
		}
	}
}g;

int main(int argc, char const *argv[])
{
	int n = 200;
	g.init(n + 5);
	for (int i = 1; i <= n; i++) {
		string str;
		getline(cin, str);
		istringstream iss;
		iss.str(str);
		int id, a, b;
		iss >> id;
		while (iss >> a >> b) {
			g.addEdge(id, a, b);
			g.addEdge(a, id, b);
		}
	}
	int dst[] = {7,37,59,82,99,115,133,165,188,197};
	g.SPFA(1);
	for (int i = 0; i < 10; i++)
		printf("%d,", g.dis[dst[i]]);
	return 0;
}