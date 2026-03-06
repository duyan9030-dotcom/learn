#include <bits/stdc++.h>
using namespace std;
int sg[21];
bool apper[101];
void build()
{
    for (int i = 1; i < 21; i++)
    {
        memset(apper, 0, sizeof(apper));
        for (int j = i - 1; j >= 0; j--)
        {
            for (int k = j; k >= 0; k--)
            {
                apper[sg[j] ^ sg[k]] = true;
            }
        }
        for (int s = 0; s < 101; s++)
        {
            if (!apper[s])
            {
                sg[i] = s;
                break;
            }
        }
    }
}
void solve()
{
    int n;
    cin >> n;
    vector<int> nums(n);
    for (int i = n - 1; i >= 0; i--)
        cin >> nums[i];
    int eor = 0;
    for (int i = n - 1; i >= 0; i--)
        if (nums[i] % 2 == 1)
            eor ^= sg[i];
    if (eor == 0)
    {
        cout << "-1 -1 -1"<<endl;
        cout << 0 << endl;
        return;
    }
    int cnt = 0, a = -1, b = -1, c = -1, pos;
    for (int i = n - 1; i >= 1; i--)
    {
        if (nums[i] > 0)
        
        {
            for (int j = i - 1; j >= 0; j--)
            {
                for (int k = j; k >= 0; k--)
                {
                    pos = eor ^ sg[i] ^ sg[j] ^ sg[k];
                    if (pos == 0)
                    {
                        cnt++;
                        if (a == -1)
                        {
                            a = i, b = j, c = k;
                        }
                    }
                }
            }
        }
    }
    cout << n - 1 - a << " " << n - 1 - b << " " << n - 1 - c << endl;
    cout << cnt << endl;
    return;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    build();
    while (t--)
        solve();
}