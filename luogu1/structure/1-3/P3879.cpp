#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    unordered_map<string, vector<int>> map;
    for (int i = 1; i <= n;i++)
    {
        int l;
        cin >> l;
        string t;
        for (int j = 0; j < l;j++)
        {
            cin >> t;
            //需要看这个单词在同一段文章里有没有出现过
            if(map[t].empty()||map[t][map[t].size()-1]!=i)
                map[t].push_back(i);
        }
    }
    int q;
    cin >> q;
    string t;
    while(q--)
    {
        cin >> t;
        for (int i = 0; i < map[t].size();i++)
            cout << map[t][i] << ' ';
        cout << endl;
    }
}