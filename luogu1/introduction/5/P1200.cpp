#include<bits/stdc++.h>
using namespace std;
int main()
{
    string s, t;
    cin >> s >> t;
    int a = 1, b = 1;
    for (int i = 0; i < s.size();i++)
    {
        a *= s[i] - 'A' + 1;
    }
    for (int i = 0; i < t.size();i++)
    {
        b *= t[i] - 'A' + 1;
    }
    if(a%47==b%47)
        cout << "GO";
    else
        cout << "STAY";
        return 0;
}