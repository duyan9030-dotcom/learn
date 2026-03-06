#include <bits/stdc++.h>
using namespace std;
int n, k;
int main()
{
    int n, k;
    cin >> n >> k;
    int a[10005];
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    for (int i = 1; i <= k; i++)
        next_permutation(a + 1, a + 1 + n); // 将当前排列更改为 全排列中的下一个排列。如果当前排列已经是 全排列中的最后一个排列（元素完全从大到小排列），函数返回 false 并将排列更改为 全排列中的第一个排列（元素完全从小到大排列）；否则，函数返回 true。
    for (int i = 1; i <= n;i++)
        cout << a[i]<<" ";
        return 0;
}