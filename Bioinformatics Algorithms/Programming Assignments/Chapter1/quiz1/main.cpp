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

int find_substring(string pattern, string text) {
	int n = pattern.size();
	vector<int> next(n + 1, 0);
	for (int i = 1; i < n; i++) {
		int j = i;
		while (j > 0) {
			j = next[j];
			if (pattern[j] == pattern[i]) {
				next[i + 1] = j + 1;
				break;
			}
		}
	}

	vector<int> position;
	int m = text.size();
	for (int i = 0, j = 0; i < m; i++) {
		if (j < n && text[i] == pattern[j]) {
			j++;
		} else {
			while (j > 0) {
				j = next[j];
				if (text[i] == pattern[j]) {
					j++;
					break;
				}
			}
		}
		if (j == n) {
			position.push_back(i - n + 1);
		} 
	}
	return position.size();
//	return position;
}

int main() {
	string text;
	cin >> text;
	int k;
	cin >> k;
	int mx = 0;
	for (int i = 0; i + k - 1 < SZ(text); i++) {
		string pattern = text.substr(i, k);	
		int temp = find_substring(pattern, text);
		if (temp > mx) {
			mx = temp;
		}
	}
	set<string> st;
	for (int i = 0; i + k - 1 < SZ(text); i++) {
		string pattern = text.substr(i, k);
		int temp = find_substring(pattern, text);
		if (temp == mx) {
			st.insert(pattern);
		}
	}
	for (set<string>::iterator it = st.begin(); it != st.end(); it++) {
		cout << *it << " ";
	}
	cout << endl;
	return 0;
}
