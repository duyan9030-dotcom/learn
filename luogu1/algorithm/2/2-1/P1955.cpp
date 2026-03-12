#include <bits/stdc++.h>
using namespace std;
const int mod = 1e9 + 7;
// 相等的值放在一个集合
int father[200005];
int find(int a)
{
    if (father[a] != a)
        father[a] = find(father[a]);
    return father[a];
}
void unite(int a, int b)
{
    father[find(a)] = find(b);
}
bool isoset(int a, int b)
{
    return find(a) == find(b);
}
struct con
{
    int i, j, e;
};
void solve()
{
    int n;
    cin >> n;
    vector<con> que(n);
    vector<int> a;
    for (int i = 0; i < n; i++)
    {
        cin >> que[i].i >> que[i].j >> que[i].e;
        a.push_back(que[i].i);
        a.push_back(que[i].j);
    }
    sort(a.begin(), a.end());
    a.erase(unique(a.begin(), a.end()), a.end());
    auto getid = [&](int x)
    {
        return lower_bound(a.begin(), a.end(), x) - a.begin() + 1;
    };
    for (int i = 1; i <= a.size(); i++)
        father[i] = i;
    for (int k = 0; k < n; k++)
        if (que[k].e == 1)
            unite(getid(que[k].i), getid(que[k].j));
    bool ans = true;
    for (int k = 0; k < n; k++)
        if (que[k].e == 0)
            if (isoset(getid(que[k].i), getid(que[k].j)))
            {
                ans = false;
                break;
            }
    if(ans)
        cout << "YES" << endl;
    else
        cout << "NO" << endl;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--)
        solve();
}