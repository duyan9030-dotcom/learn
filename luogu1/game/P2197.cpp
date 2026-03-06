#include <bits/stdc++.h>
using namespace std;
const int mod = 1e9 + 7;
void solve()
{
    int n,x;
    cin >> n;
    int xorsum = 0;
    while(n--)
    {
        cin >> x;
        xorsum ^= x;
    }
    if(xorsum==0)
        cout << "No"<<endl;
    else
        cout << "Yes" << endl;
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