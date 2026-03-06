#include <bits/stdc++.h>
using namespace std;
bool hashmap[1000005];
int idx(string s)
{
    int idx = 0;
    for (int i = 0; i < s.size(); i++)
    {
        idx += (s[i] - '0') * 31;
        idx %= 1000005;
    }
    return idx;
}
bool find(string s)
{
    return hashmap[idx(s)];
}

void insert(string s)
{
    int index = idx(s);
    hashmap[index] = 1;
}
int main()
{
    int n, sum = 0;
    unordered_map<string, bool> map;
    cin >> n;
    string s;
    for (int i = 1; i <= n; i++)
    {
        cin >> s;
        if (!find(s))
            sum++;
        insert(s);
    }
    cout << sum;
}