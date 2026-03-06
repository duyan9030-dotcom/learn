#include <bits/stdc++.h>
using namespace std;
string s = "";
char t;
void work(int m)
{
    int a = 0, b = 0;
    for (char i : s)
    {
        if (i == 'W')
            a++;
        if (i == 'L')
            b++;
        if (max(a, b) >= m && abs(a - b) >= 2)//不加时即先得m分且领先至少2分胜，加时后先领先2分者胜
        {
            cout << a << ":" << b << endl;
            a = b = 0;
        }
    }
    cout << a << ":" << b << endl<<endl;
}
int main()
{
    while (cin >> t&&t!='E')
        s += t;
    work(11),work(21);
    return 0;
}