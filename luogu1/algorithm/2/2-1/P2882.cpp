#include <bits/stdc++.h>
using namespace std;
typedef __int128 int128;
typedef long long ll;
typedef pair<int, int> pii;
const int mod = 1e9 + 7;
int n;
char a[5005];
int f[5005];
int solve(int k)
{
    memset(f, 0, sizeof(f));
    int res = 0;
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        if (i >= k)
            sum -= f[i - k];
        if ((a[i] + sum) % 2 != 0)
        {
            if (i + k > n)
                return -1;
            f[i] = 1;
            sum++;
            res++;
        }
    }
    return res;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        char c;
        cin >> c;
        a[i] = (c == 'B' ? 1 : 0);
    }
    int minM = n + 1, bestk = 1;
    for (int k = 1; k <= n; k++)
    {
        int m = solve(k);
        if (m != -1 && m < minM)
        {
            minM = m;
            bestk = k;
        }
    }
    cout << bestk << " " << minM;
    return 0;
}