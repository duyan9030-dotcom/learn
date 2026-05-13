#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
const int mod = 1e9 + 7;
int p[200005];
int le[200005];
int ri[200005];
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    string s, ss = "#";
    cin >> s;
    for (char c : s)
    {
        ss += c;
        ss += '#';
    }
    int n = ss.size();
    for (int i = 0, r = 0, c = 0, len; i < n; i++)
    {
        len = r > i ? min(p[2 * c - i], r - i) : 1;
        while (i + len < n && i - len >= 0 && ss[i + len] == ss[i - len])
            len++;
        if (i + len > r)
        {
            r = i + len;
            c = i;
        }
        p[i] = len;
        le[i + len - 1] = max(le[i + len - 1], len - 1);
        ri[i - len + 1] = max(ri[i - len + 1], len - 1);
    }
    int ans = -1;
    for (int i = n - 1; i >= 2; i--)
        le[i - 2] = max(le[i - 2], le[i] - 2);
    for (int i = 0; i <= n - 3; i++)
        ri[i + 2] = max(ri[i + 2], ri[i] - 2);
    for (int i = 0; i < n; i += 2)
        if (le[i] > 0 && ri[i] > 0)
            ans = max(ans, le[i] + ri[i]);
    cout << ans;
}