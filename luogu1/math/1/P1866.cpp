#include <bits/stdc++.h>
using namespace std;
const int mod = 1e9 + 7;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    long long n, ans = 1;
    cin >> n;
    vector<int> m(n);
    for (int i = 0; i < n; i++)
        cin >> m[i];
    sort(m.begin(), m.end());
    for (int i = 0; i < n; i++)
        ans = (ans * (m[i] - i)) % mod;
    if (ans > 0)
        cout << ans;
    else
        cout << 0;
}