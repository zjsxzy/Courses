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

int main() {
	string s;
	cin >> s;
	vector<int> skew(SZ(s) + 1);
	int mn = 10000000;
	//cout << skew[0];
	for (int i = 1; i <= SZ(s); i++) {
		if (s[i - 1] == 'C') skew[i] = skew[i - 1] - 1;
		else if (s[i - 1] == 'G') skew[i] = skew[i - 1] + 1;
		else skew[i] = skew[i - 1];
		mn = min(mn, skew[i]);
		//cout << " " << skew[i];
	}
	for (int i = 1; i <= SZ(s); i++) {
		if (skew[i] == mn) cout << i << " ";
	}
	cout << endl;
	return 0;
}
