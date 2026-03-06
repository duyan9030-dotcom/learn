#include <bits/stdc++.h>
using namespace std;
// 等差数列差分模板
int n, m;
long long life[10000005];
void f(int l, int r, int s, int e, int d)
{
    life[l] += s;
    life[l + 1] += d - s;
    life[r + 1] -= d + e;
    life[r + 2] += e;
}
void build()
{
    for (int i = 1; i <= n; i++)
        life[i] += life[i - 1];
    for (int i = 1; i <= n; i++)
        life[i] += life[i - 1];
}
int main()
{
    // cin >> n >> m;
    scanf("%d%d", &n, &m);
    int l, r, s, e;
    for (int i = 1; i <= m; i++)
    {
        // cin >> l >> r >> s >> e;
        scanf("%d%d%d%d", &l, &r, &s, &e);
        f(l, r, s, e, (e - s) / (r - l));
    }
    build();
    long long xorsum = 0, m = LONG_LONG_MIN;
    for (int i = 1; i <= n; i++)
    {
        xorsum ^= life[i];
        m = max(m, life[i]);
    }
    cout << xorsum << " " << m;
}
