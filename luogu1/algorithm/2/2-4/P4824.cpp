#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
string s1, s2;
vector<int> buildnext(string s)
{
    vector<int> next(s.size());
    next[0] = -1;
    int i = 2, cn = 0;
    while (i < s.size())
    {
        if (s[i - 1] == s[cn])
        {
            next[i++] = ++cn;
        }
        else if (cn > 0)
        {
            cn = next[cn];
        }
        else
        {
            next[i++] = 0;
        }
    }
    return next;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> s1 >> s2;
    vector<int> next = buildnext(s2);
    stack<pii> stack;
    int x = 0, y = 0;
    while (x < s1.size())
    {
        if (s1[x] == s2[y])
        {
            stack.push({x, y});
            x++, y++;
        }
        else if (y == 0)
        {
            stack.push({x, -1});
            x++;
        }
        else
        {
            y = next[y];
        }
        if (y == s2.size())
        {
            int t = y;
            while (t--)
                stack.pop();
            if (!stack.empty())
                y = stack.top().second + 1;
            else
                y = 0;
        }
    }
    string ans = "";
    while (!stack.empty())
    {
        ans += s1[stack.top().first];
        stack.pop();
    }
    int l = 0, r = ans.size() - 1;
    while (l <= r)
    {
        swap(ans[l], ans[r]);
        l++, r--;
    }
    cout << ans;
}