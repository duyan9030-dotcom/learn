#include <bits/stdc++.h>
using namespace std;
const long long mod = (1e9 + 7);
long long n, maxa, mina = 1e9, ans = 0;
long long l[100005], num[5005];
int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> l[i];
        maxa = max(maxa, l[i]);
        mina = min(mina, l[i]);
        num[l[i]]++;
    }
    for (int i = mina + 1; i <= maxa; i++)
    {
        if (num[i] >= 2)
        {
            for (int j = mina; j <= i / 2; j++)
            {
                if (num[j] >= 1 && num[i - j] >= 1)
                {
                    if (j * 2 != i)
                    {
                        ans = (ans + (num[i] * (num[i] - 1) / 2) * num[j] * num[i - j] % mod) % mod;
                    }
                    else if (num[j] > 1)
                    {
                        ans = (ans + ((num[i] * (num[i] - 1) / 2) * (num[j] * (num[j] - 1) / 2) % mod) % mod) % mod;
                    }
                }
            }
        }
    }
    cout << ans % mod;
}