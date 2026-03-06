#include <bits/stdc++.h>
using namespace std;
string turn(int a) // 数字到字符串转化
{
    string t;
    while (a != 0)
    {
        t += a % 10 + '0';
        a /= 10;
    }
    reverse(t.begin(), t.end()); // t==a
    return t;
}
string div(string s, int b)
{
    string res = "";
    int remain = 0;
    for (int i = 0; i < s.size();i++)
    {
        remain = remain * 10 + (s[i] - '0');
        if(res.size()>0||remain/b>0)
            res += (remain / b) + '0';
        remain %= b;
    }
    return res.empty() ? "0" : res;
}

string mult(string s, int b) // 高精度数*单精度数
{
    if(s=="0"||b==0)
        return "0";
    string res = "";
    int carry = 0;
    for (int i = s.size() - 1; i >= 0;i--)
    {
        int cur = (s[i] - '0') * b + carry;
        res += (cur % 10) + '0';
        carry = cur / 10;
    }
    while(carry)
    {
        res += (carry % 10) + '0';
        carry /= 10;
    }
    reverse(res.begin(), res.end());
    return res;
}

string max(string a, string b) // 字符串比较
{
    if (a.size() > b.size())
        return a;
    if (a.size() < b.size())
        return b;
    for (int i = 0; i < a.size(); i++)
    {
        if (a[i] > b[i])
            return a;
        else if (a[i] < b[i])
            return b;
    }
    return a;
}
int main()
{
    int n, a, b;
    cin >> n >> a >> b;
    vector<pair<int, int>> ab(n);
    for (int i = 0; i < n; i++)
        cin >> ab[i].first >> ab[i].second;
    sort(ab.begin(), ab.end(), [](pair<int, int> a, pair<int, int> b)
         { return a.second * a.first < b.second * b.first; });
    string t = turn(a);
    string ans = div(t, ab[0].second);
    for (int i = 1; i < n; i++)
    {
        t = mult(t, ab[i - 1].first);
        ans = max(ans, div(t, ab[i].second));
    }
    cout << ans << endl;
    return 0;
}
