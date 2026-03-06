#include <bits/stdc++.h>
using namespace std;
int main()
{
    int w, n, sum = 0;
    cin >> w >> n;
    vector<int> p(n);
    for (int &a : p)
        cin >> a;
    sort(p.begin(), p.end());
    int l = 0, r = n-1;
    while (!p.empty() && l <= r && r >= 0)
    {
        sum++;
        if (p.size() == 1)
            break;
        if (p[l] + p[r] <= w)
            l++;
        r--;
    }
    cout << sum;
}