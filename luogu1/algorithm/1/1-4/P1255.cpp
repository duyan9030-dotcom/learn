#include <bits/stdc++.h>
using namespace std;
string stair[5005];
string add(string s1, string s2)
{
    int t1[5000]={0}, t2[5000]={0};
    for (int i = s1.size() - 1; i >= 0; i--)
        t1[s1.size() - i - 1] = s1[i] - '0';
    for (int i = s2.size() - 1; i >= 0; i--)
        t2[s2.size() - i - 1] = s2[i] - '0';
    for (int i = 0; i < max(s1.size(), s2.size()); i++)
    {
        t1[i] += t2[i];
        if (t1[i] >= 10)
        {
            t1[i + 1] += t1[i] / 10;
            t1[i] %= 10;
        }
    }
    string s = "";
    int head = 4999;
    while (t1[head] == 0)
        head--;
    for (; head >= 0; head--)
    {
        s += '0' + t1[head];
    }
    return s;
}
int main()
{
    int n;
    cin >> n;
    stair[1] = "1";
    stair[2] = "2";
    for (int i = 3; i <= n; i++)
    {
        stair[i] = add(stair[i - 1], stair[i - 2]);
    }
    cout << stair[n];
    return 0;
}