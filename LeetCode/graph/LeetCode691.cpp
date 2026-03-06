#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int l = 0, r = 0;
    string queue[2000];
    vector<vector<string>> graph{26};
    unordered_map<string, bool> visited;
    string n(string t, string s)
    {
        string next;
        for (int i = 0, j = 0; i < t.size();)
            if (j == s.size())
                next += t[i++];
            else
            {
                if (t[i] < s[j])
                    next += t[i++];
                else if (t[i] > s[j])
                    j++;
                else
                    i++, j++;
            }
        return next;
    }
    int minStickers(vector<string> &stickers, string target)
    {
        sort(target.begin(), target.end());
        for (string &s:stickers)
        {
            sort(s.begin(), s.end());
            for (int j = 0; j < s.size(); j++)
                if (j == 0 || s[j] != s[j - 1])
                    graph[s[j] - 'a'].push_back(s);
        }
        visited[target] = 1;
        queue[r++] = target;
        int level = 0;
        while (l < r)
        {
            int size = r-l;
            for (int i = 0; i < size; i++)
            {
                string cur = queue[l++];
                for (string s : graph[cur[0] - 'a'])
                {
                    string next = n(cur, s);
                    if (next == "")
                        return level + 1;
                    else if (!visited[next])
                    {
                        visited[next] = 1;
                        queue[r++] = next;
                    }
                }
            }
            level++;
        }
        return -1;
    }
};