#include <bits/stdc++.h>
using namespace std;
string s;
int main()
{
    cin >> s;
    int k[3]={0};
    for (int i = 0; i < s.size();i+=5)
    {
        if (s[i] == 'a'||s[i]=='b'||s[i]=='c')
        {
            if (s[i+3]>='a'&&s[i+3]<='c')
                k[s[i]-'a'] = k[s[i+3]-'a'];
            else
                k[s[i]-'a'] = s[i+3] - '0';
        }
    }
    cout << k[0] << " " << k[1] << " " << k[2];
    return 0;
}