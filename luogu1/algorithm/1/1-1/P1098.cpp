#include <bits/stdc++.h>
using namespace std;
bool zm(char a,char b)
{
    if ((a >= 'a' && a <= 'z') && (b >= 'a' && b <= 'z') || (a >= '0' && a <= '9') && (b >= '0' && b <= '9'))
        return true;
    return false;
}
int main()
{
    int p1, p2, p3;
    cin >> p1 >> p2 >> p3;
    string s;
    cin >> s;
    for (int i = 0; i < s.size() - 2; i++)
    {
        if (s[i] < s[i + 2] && s[i + 1] == '-'&&zm(s[i],s[i+2]))
        {
            int k = s[i + 2] - s[i];
            string s1 = ""; // 循环字符
            bool yn = s[i] >= 'a' && s[i] <= 'z';//判断是字母还是数字
            for (int j = 1; j < k; j++)
                for (int z = 0; z < p2; z++)
                {
                    if (p1 == 1)
                        s1 += s[i] + j;
                    else if (p1 == 2&&yn==1)
                        s1 += s[i] + j - 32;
                    else if(p1==2&&yn==0)
                        s1 += s[i] + j;
                    else if (p1 == 3)
                        s1 += '*';
                }
            if (p3 == 2)
            {
                string s2;
                for (int j = s1.size() - 1; j >= 0; j--)
                    s2 += s1[j];
                s1 = s2;
            }
            s.erase(i + 1, 1);
            s.insert(i + 1, s1);
            i += s1.size();
        }
    }
    cout << s;
    return 0;
}