#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n, m;
    cin >> n;
    vector<int> a(n);
    for (int &i : a)
        cin >> i;
    vector<int> sum(n + 1);
    for (int i = 1; i <= n; i++)
        sum[i] = sum[i - 1] + a[i - 1];
    cin >> m;
    for (int i = 1; i <= m; i++)
    {
        int l, r;
        cin >> l >> r;
        cout << sum[r] - sum[l - 1] << endl;
    }
}