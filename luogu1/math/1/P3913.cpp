#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int mod = 1e9 + 7;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll n, k, h = 1, l = 1;
    cin >> n >> k;
    vector<int> r(k);
    vector<int> c(k);
    for (int i = 0; i < k; i++)
        cin >> r[i] >> c[i];
    sort(r.begin(), r.end());
    sort(c.begin(), c.end());
    for (int i = 1; i < k; i++)
    {
        if (r[i] != r[i - 1])
            h++;
        if (c[i] != c[i - 1])
            l++;
    }
    cout << n * n - (n - h) * (n - l);
}