#include <bits/stdc++.h>
using namespace std;
int main()
{
    int m;
    cin >> m;
    set<int> s;
    for (int i = 0; i < m; i++)
    {
        int op, l;
        cin >> op >> l;
        if (op == 1)
        {
            if (s.find(l) != s.end())
                cout << "Already Exist" << endl;
            else
                s.insert(l);
        }
        else
        {
            if (s.empty())
                cout << "Empty" << endl;
            else
            {
                auto it = s.lower_bound(l);
                int res;
                if (it == s.end())
                    res = *prev(it);
                else if (it == s.begin())
                    res = *it;
                else
                {
                    int a = *it;
                    int b = *prev(it);
                    if(l-b<=a-l)
                        res = b;
                    else
                        res = a;
                }
                cout << res << endl;
                s.erase(res);
            }
        }
    }
}
