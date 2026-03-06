#include <bits/stdc++.h>
using namespace std;
int n, a, b, m = INT_MAX;
int k[205], minu[205];
void dfs(int now, int sum)
{
    if (now < 1 || now > n)//如果超过楼层就退
        return;
    if (sum >= minu[now])//当前sum大于到达当前楼层的最小值退
        return;
    if (now == b)//找到了记录
    {
        m = min(sum, m);
        return;
    }
    minu[now] = sum;
    dfs(now + k[now], sum + 1);
    dfs(now - k[now], sum + 1);
}
int main()
{
    cin >> n >> a >> b;
    for (int i = 1; i <= n; i++)
    {
        cin >> k[i];
        minu[i] = INT_MAX;
    }
    dfs(a, 0);
    cout << (m == INT_MAX ? -1 : m);
}