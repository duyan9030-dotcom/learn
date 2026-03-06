// 双向广搜 折半搜索
#include <bits/stdc++.h>
using namespace std;
long long n, w;
long long arr[40];
long long lsum[1 << 20];
long long rsum[1 << 20];
//i-e 从i开始填到e
//s当前背包放了多少
//j 放到了ans第几个
int f(int i, int e, long long s, long long w, long long ans[], long long j)
{
    if (s > w)
        return j;
    if (i == e)
        ans[j++] = s;
    else
    {
        j = f(i + 1, e, s, w, ans, j);

        j = f(i + 1, e, s + arr[i], w, ans, j);
    }
    return j;
}
long long compute()
{
    int lsize = f(0, n >> 1, 0, w, lsum, 0);
    int rsize = f(n >> 1, n, 0, w, rsum, 0);
    sort(lsum, lsum + lsize);
    sort(rsum, rsum + rsize);
    long long ans = 0;
    for (int i = lsize - 1, j = 0; i >= 0;i--)
    {
        while(j<rsize&&lsum[i]+rsum[j]<=w)
            j++;
        ans += j;
    }
    return ans;
}
int main()
{
    cin >> n >> w;
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    cout << compute();
}