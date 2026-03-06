#include <bits/stdc++.h>
using namespace std;
int main()
{
    int q;
    cin >> q;
    while (q--)
    {
        int n, j = 0;
        stack<int> s;
        cin >> n;
        vector<int> t(n), r(n);
        for (int &x : t)
            cin >> x;
        for (int &x : r)
            cin >> x;
        for (int i = 0; i < n; i++)
        {
            s.push(t[i]);
            while (!s.empty() && s.top() == r[j])
            {
                ++j;
                s.pop();
            }
        }
        if (j == n)
            cout << "Yes" << endl;
        else
            cout << "No" << endl;
    }
}