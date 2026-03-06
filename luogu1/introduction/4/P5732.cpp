#include <bits/stdc++.h>
using namespace std;
int s[25][25] = {0};
int main()
{
    int n;
    cin >> n;
    s[1][1] = 1;
    for (int i = 2; i <= n; i++)
    {
        for (int j = 1; j <= i; j++)
        {
            s[i][j] = s[i - 1][j] + s[i - 1][j - 1];
        }
    }
    for (int i = 1; i <= n;i++)
    {
        for (int j = 1; j <= i;j++)
        {
            cout << s[i][j] << " ";
        }
        cout << endl;
    }
        return 0;
}