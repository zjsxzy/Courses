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

const int MAXN = 1000005;
struct BIT {
	int n;
	int C[MAXN];
	void init(int n) {
		this->n = n;
		memset(C, 0, sizeof(C));
	}
	int lowbit(int x) {
		return x & (-x);
	}
	void add(int x, int num) {
		for (int i = x; i <= n; i += lowbit(i))
			C[i] += num;
	}
	LL sum(int x) {
		LL ret = 0;
		for (int i = x; i > 0; i -= lowbit(i))
			ret += (LL)C[i];
		return ret;
	}
};
int main(int argc, char const *argv[])
{
	int n = 100000;
	vector<int> a(n);
	for (int i = 0; i < n; i++)
		cin >> a[i];
	LL ret = 0;
	BIT bit;
	bit.init(n);
	for (int i = 0; i < n; i++) {
		ret += i - bit.sum(a[i] - 1);
		bit.add(a[i], 1);
	}
	cout << ret << endl;
	return 0;
}