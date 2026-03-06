#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin >> n;
    int mi, ma;
    cin >> mi;
    ma = mi;
    for (int i = 1; i < n;i++)
    {
        int a;
        cin >> a;
        mi = min(mi, a);
        ma = max(ma, a);
    }
    cout << ma - mi;
    return 0;
}