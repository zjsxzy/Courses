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

int k, d;
set<string> st;

int match(const string &a, const string &b) {
	int res = 0;
	for (int i = 0; i < SZ(a); i++) {
		res += a[i] != b[i];
	}
	return res;
}

char com[4] = {'A', 'C', 'G', 'T'};

void dfs(string cur, int change) {
	if (change >= 1 && change <= d) {
		st.insert(cur);
	}
	if (change > d) return;
	for (int i = 0; i < SZ(cur); i++) {
		for (int k = 0; k < 4; k++) {
			if (com[k] != cur[i]) {
				string temp = cur;
				temp[i] = com[k];
				if (st.find(temp) != st.end()) continue;
				dfs(temp, change + 1);
			}
		}
	}
}

int main() {
	string pattern, text;
	cin >> text;
	cin >> k >> d;
	int mx = 0;
	vector<string> substr;
	for (int i = 0; i + k - 1 < SZ(text); i++) {
		pattern = text.substr(i, k);
		substr.PB(pattern);
		dfs(pattern, 0);
	}
	vector<string> ans;
	for (set<string>::iterator it = st.begin(); it != st.end(); it++) {
		pattern = *it;
		int cnt = 0;
		for (int i = 0; i < SZ(substr); i++) {
			if (match(substr[i], pattern) <= d)
				cnt++;
		}
		if (cnt > mx) {
			mx = cnt; ans.clear();
			ans.PB(pattern);
		} else if (cnt == mx) {
			ans.PB(pattern);
		}
	}
	for (int i = 0; i < SZ(ans); i++)
		cout << ans[i] << " ";
	cout << endl;
	return 0;
}
