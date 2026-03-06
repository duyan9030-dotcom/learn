#include <bits/stdc++.h>
using namespace std;
string zwna[8] = {"", "BangZhu", "FuBangZhu", "HuFa", "ZhangLao", "TangZhu", "JingYing", "BangZhong"};
struct person
{
    string zw; // 职位
    string na; // 名字
    int bg;    // 帮贡
    int level; // 等级
    int id;
    int zw1;
};
person bang[115];
bool cmp1(person a, person b)
{
    if (a.bg != b.bg)
        return a.bg > b.bg;
    return a.id < b.id;
}
bool cmp2(person a, person b)
{
    if (a.zw1 != b.zw1)
        return a.zw1 < b.zw1;
    if (a.level != b.level)
        return a.level > b.level;
    else
        return a.id < b.id;
}
int zws(string s)
{
    for (int i = 1; i <= 8; i++)
    {
        if (zwna[i] == s)
            return i;
    }
    return 0;
}
int main()
{
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> bang[i].na >> bang[i].zw >> bang[i].bg >> bang[i].level;
        bang[i].id = i;
        bang[i].zw1 = zws(bang[i].zw);
    }
    for (int i = 1; i <= n; i++)
        if (bang[i].zw == "BangZhu")
            swap(bang[i], bang[1]);
    int fb = 0;
    for (int i = 2; i <= n && fb < 2; i++)
        if (bang[i].zw == "FuBangZhu")
        {
            fb++;
            if (fb == 1)
                swap(bang[i], bang[2]);
            else if (fb == 2)
            {
                if (bang[2].level < bang[i].level)
                    swap(bang[2], bang[i]);
                swap(bang[i], bang[3]);
            }
        }
    sort(bang + 4, bang + n + 1, cmp1);
    for (int i = 4; i <= n; i++)//更新职位
    {
        if (i <= 5)
            bang[i].zw1 = 3;
        else if (i <= 9)
            bang[i].zw1 = 4;
        else if (i <= 16)
            bang[i].zw1 = 5;
        else if (i <= 41)
            bang[i].zw1 = 6;
        else
            bang[i].zw1 = 7;
    }
    sort(bang + 4, bang + n + 1, cmp2);
    for (int i = 1; i <= n; i++)
    {
        cout << bang[i].na << " ";
        if (i == 1)
            cout << "BangZhu";
        else if (i <= 3)
            cout << "FuBangZhu";
        else if (i <= 5)
            cout << "HuFa";
        else if (i <= 9)
            cout << "ZhangLao";
        else if (i <= 16)
            cout << "TangZhu";
        else if (i <= 41)
            cout << "JingYing";
        else
            cout << "BangZhong";
        cout << " " << bang[i].level << endl;
    }
    return 0;
}