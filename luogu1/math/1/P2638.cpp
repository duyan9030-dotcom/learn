#include <bits/stdc++.h>
using namespace std;
typedef __int128 int128;
#define ll long long
const int mod = 1e9 + 7;
int128 f[105][105];
void print(int128 x)
{
    if (x > 9)
        print(x / 10);
    putchar((char)(x % 10 + '0'));
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, a, b;
    cin >> n >> a >> b;
    for (int i = 0; i <= 100; i++)
    {
        f[i][0] = 1;
        for (int j = 1; j <= i; j++)
            f[i][j] = f[i - 1][j - 1] + f[i - 1][j];
    }
    int128 ans = f[a + n][n] * f[b + n][n];
    if (ans == 0)
        cout << 0;
    else
        print(ans);
}