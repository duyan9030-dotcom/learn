#include <bits/stdc++.h>
using namespace std;
int p[22000005];
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    string rs;
    cin >> rs;
    string s = "#";
    s.reserve(rs.size() * 2 + 2);
    s += '#';
    for (char c : rs)
    {
        s += c;
        s += '#';
    }
    int n = s.size();
    int ans = 0;
    for (int i = 0, c = 0, r = 0, len; i < n; i++)
    {
        len = r > i ? min(p[2 * c - i], r - i) : 1;
        while (i + len < n && i - len >= 0 && s[i + len] == s[i - len])
            len++;
        if (i + len > r)
            r = i + len, c = i;
        ans = max(ans, len);
        p[i] = len;
    }
    cout << ans - 1;
}