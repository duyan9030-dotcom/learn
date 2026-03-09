#include <bits/stdc++.h>
using namespace std;
const int mod = 1e9 + 7;
int gcd(int a, int b)
{
    return b == 0 ? a : gcd(b, a % b);
}
void solve()
{
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    a[1] = a[1] / gcd(a[0], a[1]);
    for (int i = 2; i < n; i++)
        a[1] = a[1] / gcd(a[i], a[1]);
    if (a[1] == 1)
        cout << "Yes" << endl;
    else
        cout << "No" << endl;
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