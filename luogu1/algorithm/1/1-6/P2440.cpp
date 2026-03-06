#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n, k, lm = 0;
    cin >> n >> k;
    vector<int> l(n);
    for (int &a : l)
        cin >> a;
    sort(l.begin(), l.end());
    if (k == 1)
    {
        cout << l[n - 1];
        return 0;
    }
    int left = 1, right = l[n - 1];
    while (left <= right)
    {
        int mid = (left + right) / 2, sum = 0;
        for (int a : l)
            sum += a / mid;
        if (sum >= k)
        {
            lm = max(lm, mid);
            left = mid+1;
        }
        else
            right = mid-1;
    }
    cout << lm;
}