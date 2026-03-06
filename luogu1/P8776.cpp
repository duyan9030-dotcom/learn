#include <bits/stdc++.h>
using namespace std;
int n, k;
int d[100005];
int a[100005];
int rights[100005];
//最长不上升子序列长度的二分
//找到<num的最左位置
int bs1(int len, int num)
{
    int l = 0, r = len - 1, m, ans = -1;
    while (l <= r)
    {
        m = (l + r) / 2;
        if (d[m] < num)
        {
            ans = m;
            r = m - 1;
        }
        else
        {
            l = m + 1;
        }
    }
    return ans;
}
//最长不下降子序列的二分·
//找到>num的最左位置
int bs2(int len, int num)
{
    int l = 0, r = len - 1, m, ans = -1;
    while (l <= r)
    {
        m = (l + r) / 2;
        if (d[m] > num)
        {
            ans = m;
            r = m - 1;
        }
        else
        {
            l = m + 1;
        }
    }
    return ans;
}
//生成辅助数组rights
//rights[i]表示一定以a[i]做开头的情况下，a[j...]上最长不下降子序列长度
//就是倒过来看的以arr[i]做结尾的最长不上升子序列长度
void right()
{
    int len = 0;
    for (int i = n, find; i >= 1;i--)
    {
        find = bs1(len, a[i]);
        if(find==-1)
        {
            d[len++] = a[i];
            rights[i] = len;
        }
        else{
            d[find] = a[i];
            rights[i] = find + 1;
        }
    }
}
int compute()
{
    right();
    int len = 0;
    int ans = 0;
    for (int i = 1, j = k, find, left; j <= n; i++, j++)
    {
        find = bs2(len, a[j]);
        left = find == -1 ? len : find;
        ans = max(ans, left + k + rights[j]);
        find = bs2(len, a[i]);
        if(find==-1)
            d[len++] = a[i];
        else
            d[find] = a[i];
    }
    ans = max(ans, len + k);
    return ans;
}
int main()
{
    cin >> n >> k;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    if (k >= n)
        cout << n;
    else
        cout << compute();
}