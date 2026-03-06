#include <bits/stdc++.h>
using namespace std;
const int mod = 1e9 + 7;
void solve()
{
    int n;
    cin >> n;
    if(n%6==0)
        cout << "Roy wins!"<<endl;
    else
        cout << "October wins!"<<endl;
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