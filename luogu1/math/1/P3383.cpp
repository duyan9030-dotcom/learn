#include <bits/stdc++.h>
using namespace std;
typedef __int128 int128;
#define ll long long
const int mod = 1e9 + 7;
vector<int> prime;
void build(int n)
{
    vector<int> vis(n + 1);
    for (int i = 2; i * i <= n; i++)
    {
        if (!vis[i])
        {
            for (int j = i * i; j <= n; j += i)
                vis[j] = true;
        }
    }
    for (int i = 2; i <= n; i++)
        if (!vis[i])
            prime.push_back(i);
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, q, x;
    cin >> n >> q;
    build(n);
    while (q--)
    {
        cin >> x;
        cout << prime[x - 1] << "\n";
    }
    return 0;
}