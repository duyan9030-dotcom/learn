#include <bits/stdc++.h>
using namespace std;
const int mod = 1e9 + 7;
int lowzero(int status)
{
    int cnt = 0;
    while(status>0)
    {
        if ((status & 1) == 0)
            break;
        status>>=1;
        cnt++;
    }
    return cnt;
}
void solve()
{
    int n,a,b,sg=0;
    cin >> n;
    for (int i = 0; i < n / 2;i++)
    {
        cin >> a >> b;
        sg ^= lowzero((a - 1) | (b - 1));
    }
    if(sg!=0)
        cout << "YES"<<endl;
    else
        cout << "NO" << endl;
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