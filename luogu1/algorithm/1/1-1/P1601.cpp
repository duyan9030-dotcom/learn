#include <bits/stdc++.h>
using namespace std;
int a[505] = {0};
int b[505] = {0};
int c[505] = {0};
int main()
{
    string s, t;
    cin >> s >> t;
    int sl = s.size(), tl = t.size();
    int m = max(sl,tl);
    for (int i = s.size() - 1; i >= 0; i--)
        if (s[i] >= '0' && s[i] <= '9')
            a[sl-i-1] = s[i] - '0';
    for (int i = t.size() - 1; i >= 0; i--)
        if (t[i] >= '0' && t[i] <= '9')
            b[tl-i-1] = t[i] - '0';
    for (int i = 0; i < m;i++)
    {
        c[i] += a[i] + b[i];//不能去掉+，否则之前的进位会消失
        if(c[i]>=10)
        {
            c[i + 1] += c[i] / 10;
            c[i] %= 10;
        }
    }
    int head = 504;
    while(c[head]==0&&head>0)
        head--;
    for (; head >= 0;head--)
        cout << c[head];
        return 0;
}