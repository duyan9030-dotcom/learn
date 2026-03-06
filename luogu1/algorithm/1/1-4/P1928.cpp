#include <bits/stdc++.h>
using namespace std;
string f(string s)
{
    if (s.find('[') == string::npos) // 没有压缩
        return s;
    string t;
    // THIS[10DAT A [ 7 I S ] ] M ADE[8BY[9NETTLE]]
    // 0123456789 101112131415161718
    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] >= 'A' && s[i] <= 'Z')
            t += s[i];
        if (s[i] == '[') // 找到与之对应的右括号去递归
        {
            int sum = 1, j = i + 1, l = i + 1;
            for (; sum != 0; j++)
            {
                if (s[j] == '[')
                    sum++;
                if (s[j] == ']')
                    sum--;
            }

            while (s[l] >= '0' && s[l] <= '9')
                sum = sum * 10 + s[l++] - '0'; // j==16,l==7
            cout << j << " " << l << endl;
            for (int k = 0; k < sum; k++)
                t += f(s.substr(l, j - l - 1));
            i = j - 1;
        }
    }
    return t;
}
int main()
{
    string s;
    cin >> s;
    cout << f(s);
}