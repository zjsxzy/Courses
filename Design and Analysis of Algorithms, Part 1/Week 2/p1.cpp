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

int n;
int Partition(int arr[], int lower, int upper) {
	int pivot = arr[lower], i = lower + 1, j = lower + 1;
	for (; j <= upper; j++) {
		if (arr[j] < pivot) {
			swap(arr[i], arr[j]);
			i++;
		}
	}
	swap(arr[lower], arr[i - 1]);
	return (i - 1);
}

int comp = 0;
int QuickSort(int arr[], int lower, int upper) {
	if (lower < upper) {
		int part = Partition(arr, lower, upper);
		comp += upper - lower;
		QuickSort(arr, lower, part - 1);
		QuickSort(arr, part + 1, upper);
	}
	return comp;
}

int main(int argc, char const *argv[])
{
	//scanf("%d", &n);
	n = 10000;
	int arr[n];
	for (int i = 0; i < n; i++)
		scanf("%d", &arr[i]);
	int ret = QuickSort(arr, 0, n - 1);
	//for (int i = 0; i < n; i++)
	//	printf("%d ", arr[i]);
	//printf("\n");
	printf("%d\n", ret);
	return 0;
}
//ans: 162085