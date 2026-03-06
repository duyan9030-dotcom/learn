#include <bits/stdc++.h>
using namespace std;
int main()
{
    int l, n, m;
    cin >> l >> n >> m;
    vector<int> s(n + 2);
    s[++n] = l;
    for (int i = 1; i <= n; i++)
        cin >> s[i];
    int left = 0, right = l;
    while (left < right)
    {
        int mid = (left+right+1)/2, sum = 0,p=0;
        for (int i = 1; i <= n; i++)
        {
            if (s[i] - p< mid)
                sum++;
            else
                p = s[i];
        }
        if (sum <= m)
            left = mid;
        else
            right = mid-1;
    }
    cout << left;
}
// 8 3 1 2 4 7 
// 2
//如果移走第一块石头，就会变成4 3 1 显然不好,需要考虑最后一步
