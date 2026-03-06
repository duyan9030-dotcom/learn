#include <bits/stdc++.h>

using namespace std;
int main()
{
    int l, n=1, sum=0;
    string s;
    cin >> s;
    l = s.size();
    for (int i = 0; i < l - 1; ++i)
        if (s[i] >= '0' && s[i] <= '9')//若输入为数字则sum加
            sum += (s[i] - '0') * n++;
    
    if (sum % 11 + '0' == s[l - 1] || (sum % 11 == 10 && s[l - 1] == 'X'))//特判
        puts("Right");
    else
        s[l - 1] = (sum % 11 == 10 ? 'X' : sum % 11 + '0'),
              cout << s;
    return 0;
}