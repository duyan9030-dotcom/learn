#include <bits/stdc++.h>
using namespace std;
int main()
{
    vector<int> n;
    int x, l;
    cin >> l;
    for (int i = 0; i < l; i++)
    {
        cin >> x;
        n.push_back(x);
    }
    bool a[n.size()];
    memset(a, 1, sizeof(a));
    for (int i = 0; i < n.size() - 1; i++)
    {
        if (abs(n[i] - n[i + 1]) >= 1 && abs(n[i] - n[i + 1]) <= l - 1)
            a[abs(n[i] - n[i + 1])] = 0;
    }
    for (int i = 1; i < n.size(); i++)
    {
        if (a[i] == 1)
        {
            cout << "Not jolly";
            return 0;
        }
    }
    cout << "Jolly";
    return 0;
}