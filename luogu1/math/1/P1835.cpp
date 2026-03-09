#include <bits/stdc++.h>
using namespace std;
typedef __int128 int128;
#define ll long long
const int mod = 1e9 + 7;
vector<int> prime;
bool vis[50005];
void build()
{
    for (int i = 2; i <= 50000; i++)
    {
        if (!vis[i])
        {
            prime.push_back(i);
            for (ll j = (ll)i * i; j < 50000; j += i)
                vis[j] = true;
        }
    }
}
bool inprime[1000005];
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll l, r;
    cin >> l >> r;
    build();
    if(l==1)
        inprime[0] = true;
    for (int p : prime)
    {
        ll cur = (l + p - 1) / p * p;
        if (cur == p)
            cur += p;
        for (ll j = cur; j <= r; j += p)
            inprime[j - l] = true;
    }
    int sum = 0;
    for (ll i = 0; i <= r - l; i++)
        if (!inprime[i])
            sum++;
    cout << sum;
}