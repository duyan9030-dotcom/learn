#include <bits/stdc++.h>
using namespace std;
const int mod = 1e9 + 7;
int main()
{
    int n, m;
    string num;
    cin >> n >> num >> m;
    int tnum = 0; // 转换后的10进制数字
    for (int i = num.size() - 1; i >= 0; i--)
    {
        if (num[i] >= '0' && num[i] <= '9')
            tnum += (num[i] - '0') * pow(n, num.size() - i - 1);
        else
            tnum += (num[i] - 'A' + 10) * pow(n, num.size() - i - 1);
    }
    string ttnum = "";
    while (tnum != 0)
    {
        int cur = tnum % m;
        tnum /= m;
        if (cur <= 9)
            ttnum += cur + '0';
        else
            ttnum += cur - 10 +'A';
        // cout << ttnum << endl
        //      << tnum << endl;
    }
    reverse(ttnum.begin(), ttnum.end());
    cout << ttnum;
}