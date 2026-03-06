#include <bits/stdc++.h>
using namespace std;
const int mod = 1e9 + 7;
int main()
{
    long long a;
    cin >> a;
    string s1 = "";
    while(a!=0)
    {
        int cur = a % 2;
        a /= 2;
        s1 += cur + '0';
    }
    while(s1.size()<32)
    {
        s1 += '0';
    }
    reverse(s1.begin(), s1.end());
    for (int i = 0; i <= 15;i++)
        swap(s1[i], s1[i + 16]);
    long long num = 0;
    for (int i = 31; i >= 0;i--)
        num += pow(2, 32 - i - 1) * (s1[i] - '0');
    cout << num;
}