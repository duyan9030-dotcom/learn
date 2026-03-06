#include <bits/stdc++.h>
using namespace std;
int main()
{
    string s;
    long long n;
    cin >> s >> n;
    int l = s.length();
    while(l<n)
    {
        long long i = l;
        while(n>i)
            i *= 2;
        i /= 2;
        n -= i + 1;
        if (n == 0)
            n = i;
    }
    cout << s[n-1];
}