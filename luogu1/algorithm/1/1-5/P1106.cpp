#include <bits/stdc++.h>
using namespace std;
int main()
{
    string s;
    int k;
    cin >> s >> k;
    s += '0';
    while (k)
        for (int i = 0; i < s.size(); i++)
            if (s[i] > s[i + 1])
            {
                s.erase(i, 1);
                k--;
                break;
            }
    s.erase(s.size() - 1, 1);
    while (s[0] == '0')
        s.erase(0, 1);
    cout << (s.size() == 0 ? "0" : s);//等号优先级比？高
}