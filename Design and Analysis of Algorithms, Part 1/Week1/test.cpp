#include<cstdio>
#include <iostream>
#define MAXN 100001

using namespace std;

int n, m, maxnum, ans;
long long tot;
int a[MAXN];
void merge(int l, int mid, int r)
{
    int i, j, t;
    int tmp[MAXN];
    t = l;
    i = l;
    j = mid + 1;
    while (t <= r)
    {
        if ((i <= mid) && ((j > r) || (a[i] > a[j])))
        {
            tmp[t] = a[i];
            i++;
        }
        else
        {
            tmp[t] = a[j];
            j++;
            tot += i-l;
        }
        t++;
    }
    for (i = l; i <= r; i++)
        a[i] = tmp[i];
}
void mergesort(int l, int r)
{
    int mid;
    mid = (l + r) / 2;
    if (l != r)
    {
        mergesort(l, mid);
        mergesort(mid + 1, r);
        merge(l, mid, r);
    }
}
int main()
{
    maxnum = -1;
    n = 100000;
        tot = 0;
        for (int j = 1; j <= n; j++)
            scanf("%d", &a[j]);
        mergesort(1, n);
    printf("%lld\n", tot);
    return 0;
}