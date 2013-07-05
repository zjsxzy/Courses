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

char ch[100] = "09e1c5f70a65ac519458e7e53f36";
int out[55];
int key[55];

int hex(char x) {
	if ('0' <= x && x <= '9') return x - '0';
	return x - 'a' + 10;
}
int change(char a, char b) {
	int aa = hex(a);
	int bb = hex(b);
	return aa * 16 + bb;
}
int main(int argc, char const *argv[])
{
	for (int i = 0; i + 1 < 28; i += 2)
		out[i / 2] = change(ch[i], ch[i + 1]);
	string str;
	getline(cin, str);
	for (int i = 0; i < str.size(); i++) {
		key[i] = str[i] ^ out[i];
	}
	for (int i = 0; i < str.size(); i++) {
		printf("%d %2x\n", i, key[i]);
	}
	cout << endl;
	getline(cin, str);
	for (int i = 0; i < str.size(); i++) {
		printf("%2x", str[i] ^ key[i]);
	}
	cout << endl;
	return 0;
}
