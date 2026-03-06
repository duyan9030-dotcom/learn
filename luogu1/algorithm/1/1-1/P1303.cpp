#include <bits/stdc++.h>
using namespace std;
int a[2010] = {0};
int b[2010] = {0};
int c[4050] = {0};
int main()
{
    string s, t;
    cin >> s >> t;
    int sl = s.size(), tl = t.size();
    if(s=="0"||t=="0")
    {
        cout << 0;
        return 0;
    }
    if (sl < tl)
    {
        string l = s;
        s = t;
        t = l;
    }
    for (int i = sl - 1; i >= 0; i--)
        if (s[i] >= '0' && s[i] <= '9')
            a[sl - i - 1] = s[i] - '0';
    for (int i = tl - 1; i >= 0; i--)
        if (t[i] >= '0' && t[i] <= '9')
            b[tl - i - 1] = t[i] - '0';
    for (int i = 0; i < sl; i++)
        for (int j = 0; j < tl; j++)
        {
            c[i + j] += a[i] * b[j];
            if (c[i + j] >= 10)
            {
                c[i + j + 1] += c[i + j] / 10;
                c[i + j] %= 10;
            }
        }
    int head = 4049;
    while (head >= 0 && c[head] == 0)
        head--;
    for (; head >= 0; head--)
        cout << c[head];
    return 0;
}