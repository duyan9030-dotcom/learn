#include <bits/stdc++.h>
using namespace std;
int main()
{
    int l, m;
    cin >> l >> m;
    const int x = l;
    int flag[x+1] = {0};
    for (int i = 0; i < m;i++)//开辟l长度数组全部置0；若为0并且在范围内就置1
    {
        int u, v;
        cin>>u>>v;
        for (int i = u; i <= v;i++)
        {
            if(!flag[i])
                flag[i] = 1;
        }
    }
    int ans = 0;
    for (int i = 0; i <= l;i++)
    {
        if(!flag[i])//若为0即未移走则ans++
            ans++;
    }
    cout << ans;
    return 0;
}