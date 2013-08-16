#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <queue>
#include <vector>
#include <limits.h>
using namespace std;

priority_queue<int> maxheap;
priority_queue<int, vector<int>, greater<int> > minheap;

void insert(int x) {
	if (x <= maxheap.top()) maxheap.push(x);
	else minheap.push(x);
	if (minheap.size() > maxheap.size()) {
		int x = minheap.top();
		minheap.pop();
		maxheap.push(x);
	} else if (maxheap.size() > minheap.size() + 1) {
		int x = maxheap.top();
		maxheap.pop();
		minheap.push(x);
	}
}

int findmedian() {
	return maxheap.top();
}

int ans = 0;
int x;
int main() {
	minheap.push(INT_MAX);
	maxheap.push(-INT_MAX);
	while (scanf("%d", &x) != -1) {
		insert(x);
		ans += findmedian();
		ans %= 10000;
	}
	printf("%d\n", ans);
	return 0;
}
