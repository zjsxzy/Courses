#include <cstdio>
#include <vector>
#include <iostream>
using namespace std;

const int N = 40;

template <class T>
inline void sum(T &p, int n, vector<T> &d) {
	p = 0;
	for (int i = 0; i < n; i++)
		p += d[i];
}

int main() {
	int accum = 0;
	vector<int> data(N);
	for (int i = 0; i < N; i++)
		data[i] = i;
	// sum all elements in data
	sum(accum, N, data);
	cout << accum << endl;
	return 0;
}
