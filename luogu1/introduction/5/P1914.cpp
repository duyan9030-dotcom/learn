#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n,i=0;
    string s;
    cin >> n>>s;
    while(i<s.size())
        s[i++] += s[i] + n > 'z' ? n - 26 : n;
    cout << s;
    return 0;
}