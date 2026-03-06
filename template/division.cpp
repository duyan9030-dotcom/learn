#include <bits/stdc++.h>
using namespace std;
//单精度除单精度
// int main()
// {
//     int a = 0, b = 0, n = 0;
//     cin >> a >> b >> n;
//     cout << a / b << '.';
//     int t = a % b;
//     while(t!=0&&n--)
//     {
//         t *= 10;
//         cout << t / b;
//         t = t % b;
//     }
// }
//高/单
// int main()
// {
//     string s;
//     cin >> s;
//     int a[250] = {0};
//     int b = 0;
//     int c[250] = {0};
//     cin >> b;
//     for (int i = 0; i < s.size();i++)
//         a[i] = s[i] - '0';
//     int t = 0;
//     for (int i = 0; i < s.size();i++)
//     {
//         t = t * 10 + a[i];
//         if(t>=b)
//         {
//             c[i] = t / b;
//             t = t % b;
//         }
//         else
//             c[i] = 0;
//     }
//     int index = 0;
//     while(c[index++]!=0)
//         ;
//     while(index<s.size())
//         cout << c[index++];
// }
#include <bits/stdc++.h>
using namespace std;
int main()
{
    string s1, s2;
    int a[250], b[250],c[250];
    cin >> s1 >> s2;
    for (int i = 0; i < s1.size(); i++)
        a[i] = s1[i] - '0';
    for (int i = 0; i < s2.size(); i++)
       b[i] = s2[i] - '0';
}