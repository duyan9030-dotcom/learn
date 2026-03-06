#include <bits/stdc++.h>
using namespace std;
int main()
{
    int m, n;
    long long sum = 0;
    cin >> m >> n;
    vector<int> s(m), p(n);
    for (int &a : s)
        cin >> a;
    for (int &a : p)
        cin >> a;
    sort(s.begin(), s.end());
    for (int a : p)
    {
        int l = 0, r = m-1 , mid;
        while (l < r)
        {
            mid = (l + r) / 2;
             if (s[mid] > a)
                r = mid;
            else
                l = mid + 1;
        }
            sum += a <= s[0] ? s[0] - a : min(abs(a - s[l - 1]), abs(a - s[l]));
    }
    cout << sum;
}