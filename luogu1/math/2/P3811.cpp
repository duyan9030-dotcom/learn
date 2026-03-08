#include <bits/stdc++.h>
using namespace std;
#define ll long long
int n, p;
int inv[3000005];
void build()
{
    inv[1] = 1;
    for (int i = 2; i <= n; i++)
        inv[i] = (int)(p - (ll)inv[p % i] * (p / i) % p);
    //逆元线性递推公式
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    scanf("%d%d", &n, &p);
    build();
    for (int i = 1; i <= n; i++)
        printf("%d\n", inv[i]);
}