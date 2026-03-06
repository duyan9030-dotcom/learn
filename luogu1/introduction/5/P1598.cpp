#include <bits/stdc++.h>
using namespace std;
int alpa[30] = {0};
int main()
{
    string s[4];
    int m = 0, n;
    for (int i = 0; i < 4; i++)
        getline(cin, s[i]);
    for (int i = 0; i < 4;i++)
    {
        for (int j = 0; j < s[i].size();j++)
        {
            if(s[i][j]>='A'&&s[i][j]<='Z')
            {
                alpa[s[i][j] - 'A']++;
            }
        }
    }
    for (int i = 0; i < 26;i++)
        m = max(m, alpa[i]);
    n = m;
    for (int i = 0; i < n;i++)
    {
        for (int j = 0; j < 26;j++)
        {
            if(alpa[j]==m)
            {
                cout << "* ";
                alpa[j]--;
            }
            else
                cout << "  ";
        }
        m--;
        cout << endl;
    }
    cout << "A B C D E F G H I J K L M N O P Q R S T U V W X Y Z";
    return 0;
}