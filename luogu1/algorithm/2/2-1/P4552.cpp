#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
const int mod = 1e9 + 7;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    vector<int> a(n);
    for (int &x : a)
        cin >> x;
    vector<int> d(n);
    ll f = 0, z = 0;
    for (int i = 1; i < n; i++)
    {
        d[i] = a[i] - a[i - 1];
        if (d[i] < 0)
            f -= d[i];
        if (d[i] > 0)
            z += d[i];
    }
    cout << max(f, z) << endl;
    cout << abs(f - z) + 1;
}