#include <bits/stdc++.h>
using namespace std;
int main()
{
    string s;
    bool k[105];
    cin >> s;
    for (int i = 0; i < s.size(); i++)
        if (s[i] == ')')
        {
            for (int j = i - 1; j >= 0; j--)
                if (s[j] == '(' && !k[j])
                {
                    k[i] = k[j] = 1;
                    break;
                }
                else if (s[j] == '[' && !k[j])
                    break;
        }
        else if (s[i] == ']')
        {
            for (int j = i - 1; j >= 0; j--)
                if (!k[j] && s[j] == '[')
                {
                    k[i] = k[j] = 1;
                    break;
                }
                else if (s[j] == '(' && !k[j])
                    break;
        }
    for (int i = 0; i < s.size(); i++)
        if (!k[i])
            if (s[i] == '(' || s[i] == ')')
                cout << "()";
            else
                cout << "[]";
        else
            cout << s[i];
}