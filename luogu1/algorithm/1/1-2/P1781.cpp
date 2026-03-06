#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n, m = 1;
    cin >> n;
    string s;
    cin >> s;
    for (int i = 2; i <= n; i++)
    {
        string t;
        cin >> t;
        if (s.size() != t.size())
        {
            if(s.size()<t.size())
            {
                s = t;
                m = i;
            }

        }
        else
        {
            for (int j = 0; j < s.size(); j++)
            {
                if (s[j] - '0' > t[j] - '0')
                {
                    break;
                }
                if (s[j] - '0' < t[j] - '0')
                {
                    s = t;
                    m = i;
                    break;
                }
            }
        }
    }
    cout << m << endl
         << s;
    return 0;
}