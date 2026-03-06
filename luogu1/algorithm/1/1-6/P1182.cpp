#include <bits/stdc++.h>
using namespace std;
int check(vector<int> a, int mid)
{
    int part = 1, sum = 0;
    for (int x : a)
    {
        if (sum + x > mid)
        {
            part++;
            sum = x;
        }
        else
            sum += x;
    }
    return part;
}
int main()
{
    int n, m, sum = 0,ma=0;
    cin >> n >> m;
    vector<int> a(n);
    for (int &x : a)
    {
        cin >> x;
        sum += x;
        ma = max(ma, x);
    }
    int l = ma, r = sum, mid, ans = 0;
    while (l <= r)
    {
        mid = (l + r) >>1;
        if (check(a, mid) <= m)
        {
            ans = mid;
            r = mid - 1;
        }
        else
            l = mid + 1;
    }
    cout << ans;
}