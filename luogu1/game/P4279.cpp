#include <bits/stdc++.h>
using namespace std;
const int mod = 1e9 + 7;
void solve()
{
    int n,sum=0,eor=0,x;
    cin >> n;
    for (int i = 0; i < n;i++)
    {
        cin >> x;
        sum += x;
        eor ^= x;
    }
    if(sum==n)
        cout << (n & 1 == 1 ? "Brother" : "John") << endl;
    else
        cout << (eor ? "John" : "Brother") << endl;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while(t--)
        solve();
}