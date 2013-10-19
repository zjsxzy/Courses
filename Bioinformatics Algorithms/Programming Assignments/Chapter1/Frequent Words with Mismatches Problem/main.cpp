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
vector<string> vec;
int match(string a, string b) {
	int res = 0;
	for (int i = 0; i < SZ(a); i++) {
		res += a[i] != b[i];
	}
	return res;
}

void dfs(string cur) {
	if (SZ(cur) == k) {
		vec.PB(cur);
		return;
	}
	dfs(cur + "A");
	dfs(cur + "C");
	dfs(cur + "G");
	dfs(cur + "T");
}

int main() {
	string pattern, text;
	cin >> text;
	cout << SZ(text) << endl;
	cin >> k >> d;
	int mx = 0;
	vector<string> ans;
	dfs("");
	for (int i = 0; i < SZ(vec); i++) {
		pattern = vec[i];
		int cnt = 0;
		for (int i = 0; i + SZ(pattern) - 1 < SZ(text); i++) {
			string substr = text.substr(i, SZ(pattern));
			if (match(substr, pattern) <= d) {
				cnt++;
			}
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
