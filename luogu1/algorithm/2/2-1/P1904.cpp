#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int l, h, r;
    vector<pii> events;
    while (cin >> l >> h >> r)
    {
        events.push_back({l, -h});
        events.push_back({r, h});
    }
    sort(events.begin(), events.end());
    multiset<int> heigh;
    heigh.insert(0);
    int pre = 0;
    bool is = true;
    for (auto &a : events)
    {
        int x = a.first;
        int h = a.second;
        if (h < 0)
            heigh.insert(-h);
        else
            heigh.erase(heigh.find(h));
        int cur = *heigh.rbegin();
        if (cur != pre)
        {
            if (!is)
                cout << " ";
            cout << x << " " << cur;
            pre = cur;
            is = false;
        }
    }
}