#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
const int mod = 1e9 + 7;
const ll base = 499;
vector<ull> a;
ll v(char c)
{
    if (c >= '0' && c <= '9')
        return c - '0' + 1;
    else if (c >= 'A' && c <= 'Z')
        return c - 'A' + 1;
    else
        return c - 'a' + 1;
}
ull f(string s)
{
    ll ans = v(s[0]);
    for (int i = 1; i < s.length(); i++)
        ans = ans * base + v(s[i]);
    return ans;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    string s;
    for (int i = 0; i < n; i++)
    {
        cin >> s;
        a.push_back(f(s));
    }
    sort(a.begin(), a.end());
    int ans = 1;
    for (int i = 1; i < n; i++)
        if (a[i] != a[i - 1])
            ans++;
    cout << ans;
}