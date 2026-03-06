#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n,x;
    cin >> n;
    unordered_map<int, int> map;
    for (int i = 1; i <= n;i++)
    {
        cin >> x;
        map[x] = i;
    }
    int q,m;
    cin >> q;
    while(q--)
    {
        cin >> m;
        if(map.find(m)!=map.end())
            cout << map[m]<<endl;
        else
            cout << 0 << endl;
    }
    return 0;
}