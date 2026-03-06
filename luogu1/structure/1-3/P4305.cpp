#include <bits/stdc++.h>
using namespace std;
void solve()
{
    int n, x;
    cin >> n;
    vector<int> a;
    set<int> s;
    for (int i = 0; i < n; i++)
    {
        cin >> x;
        if (s.insert(x).second)
            a.push_back(x);
    }
    for (int i = 0; i < a.size(); i++)
        cout << a[i] << ' ';
    cout << endl;
}
int main()
{
    int t;
    cin >> t;
    while (t--)
        solve();
}
