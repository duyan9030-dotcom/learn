#include <bits/stdc++.h>
using namespace std;
string q(string a) // 去除前导0
{
    for (int i = 0; i < a.size(); i++)
        if (a[i] != '0')
            return a.substr(i);
    return "";
}
string h(string a) // 去除后导0
{
    for (int i = a.size() - 1; i >= 0; i--)
        if (a[i] != '0')
            return a.substr(0, i + 1);
    return "";
}
void nixu(string a) // 逆序输出一个字符串
{
    for (int i = a.size() - 1; i >= 0; i--)
        cout << a[i];
}
int main()
{
    string s, t; // s是整数部分 //t是符号后部分
    char k = '0';
    getline(cin, s);
    for (int i = 0; i < s.size(); i++)
        if (s[i] == '.' || s[i] == '/' || s[i] == '%')
        {
            k = s[i];
            t = s.substr(i + 1);
            s.erase(i, s.size() - i);
            break;
        }
    if (s[0] != '0')
        s = h(s);
    if (k == '0' || k == '%') // 整数 20位不能用int
    {
        nixu(s);
        if (k == '%') // 百分数特判
            cout << "%";
        return 0;
    }
    if (t[0] == '0' && t.size() == 1)
    {
        t = "0";
        nixu(s);
        cout << k;
        nixu(t);
        return 0;
    }
    t = k == '/' ? h(t) : q(t);
    nixu(s);
    cout << k;
    nixu(t);
    return 0;
}