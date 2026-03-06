#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    long long ans = 0;
    cin >> n;
    vector<int> d(n);
    for(int &x:d)
        cin >> x;
    for (int i = 1; i < n;i++)
    if(d[i]>d[i-1])
        ans += d[i] - d[i - 1];
    cout << ans + d[0];
    return 0;
}