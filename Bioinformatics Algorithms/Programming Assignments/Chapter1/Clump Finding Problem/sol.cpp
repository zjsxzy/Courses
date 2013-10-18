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

const int dict = 4;
const int root = 0;
const int maxn = 3000000;
int mp[256];
int tot = 0;
int k, L, t;
void pre() {
	mp['A'] = 0;
	mp['T'] = 1;
	mp['C'] = 2;
	mp['G'] = 3;
}
string str[300000];
struct AC{
	struct node {
		int son[dict], fail, idx;
		//int bad;
	}tree[maxn];
	bool vis[maxn];
	int cnt[300100];
	int sz;

	int initNode(int idx) {
		memset(tree[idx].son, 0, sizeof(tree[idx]));
		tree[idx].fail = tree[idx].idx = 0;
		//tree[idx].bad = 0;
		return idx;
	}
	void init() {
		sz = initNode(0);
		memset(cnt, 0, sizeof(cnt));
	}
	void insert(string s, int idx) {
		int cur = root;
		for (int i = 0; i < SZ(s); i++) {
			int t = mp[s[i]];
			if (!tree[cur].son[t]) {
				tree[cur].son[t] = initNode(++sz);
			}
			cur = tree[cur].son[t];
		}
		//tree[cur].flag = true;
		//tree[idx].bad = true;
		if (tree[cur].idx != 0) cnt[tree[cur].idx]++;
		else tree[cur].idx = idx;
	}
	queue<int> q;
	void build() {
		while (!q.empty()) q.pop();
		for (int i = 0; i < dict; i++)
			if (tree[root].son[i]) {
				q.push(tree[root].son[i]);
			}
		while (!q.empty()) {
			int cur = q.front(); q.pop();
			int f = tree[cur].fail;
			for (int i = 0; i < dict; i++) {
				if (tree[cur].son[i]) {
					int nxt = tree[cur].son[i];
					tree[nxt].fail = tree[f].son[i];
					//tree[nxt].bad |= tree[tree[nxt].fail].bad;
					q.push(nxt);
				} else {
					tree[cur].son[i] = tree[f].son[i];
				}
			}
		}
	}

	vector<int> apr[300010];
	// hdu 2222
	set<string> match(string s, int L, int t) {
		int n = s.size();
		int cur = 0;
		for (int si = 0; si < n; si++) {
			cur = tree[cur].son[mp[s[si]]];
			for (int i = cur; i; i = tree[i].fail) {
				if (tree[i].idx != 0)
					apr[tree[i].idx].PB(si - k + 1);
			}
		}
		set<string> ret;
		for (int i = 1; i <= tot; i++) {
			if (apr[i].size() >= t) {
				//cout << str[i] << " " << apr[i].size() << endl;
				for (int j = 0; j + t - 1 < apr[i].size(); j++) {
					if (apr[i][j + t - 1] + k - 1 - apr[i][j] + 1 <= L) {
						ret.insert(str[i]);
						break;
					}
				}
				/*
				for (int j = 0; j < apr[i].size(); j++) {
					cout << apr[i][j] << " ";
				}
				cout << endl;
				*/
			}
		}
		return ret;
	}
}ac;

void dfs(string cur) {
	if (SZ(cur) == k) {
		ac.insert(cur, ++tot);	
		str[tot] = cur;
		return;
	}
	dfs(cur + "A");
	dfs(cur + "T");
	dfs(cur + "C");
	dfs(cur + "G");
}

int main() {
	pre();
	ac.init();
	string text;
	cin >> text;
	k = 9; L = 500; t = 3;
	//cin >> k >> L >> t;
	dfs("");
	//cout << tot << endl;
	ac.build();
	set<string> res = ac.match(text, L, t);
	cout << res.size() << endl;
	/*
	for (set<string>::iterator it = res.begin(); it != res.end(); it++) {
		cout << *it << " ";
	}
	cout << endl;
	*/
	return 0;
}
