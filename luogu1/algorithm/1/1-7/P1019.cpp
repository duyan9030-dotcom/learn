#include <bits/stdc++.h>
using namespace std;
int n;
int ans = -1;
void dfs(string last, vector<string> &s, vector<int> &count,int len)
{
    ans = max(ans, len);
    for (int i = 0; i < n; i++)
    {
        if (count[i] >= 2)
            continue;
        for (int k = 1; k < min(last.size(), s[i].size()); k++)
        {
            if (last.substr(last.size() - k) == s[i].substr(0, k))
            {
                count[i]++;
                dfs(s[i], s, count,len+s[i].size()-k);
                count[i]--;
                break;
            }
        }
    }
}
int main()
{
    cin >> n;
    vector<int> count(n);
    vector<string> s(n);
    for (int i = 0; i < n; i++)
    {
        cin >> s[i];
    }
    char start_char;
    cin >> start_char;

    // 找到所有以 start_char 开头的单词作为起点
    for (int i = 0; i < n; i++)
    {
        if (s[i][0] == start_char)
        {
            count[i]++;
            dfs(s[i], s, count, s[i].size());
            count[i]--; // 回溯
        }
    }
    cout << ans;
}