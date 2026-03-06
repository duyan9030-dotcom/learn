#include <bits/stdc++.h>
using namespace std;
char s[100];
string k[5][10] = {
    "XXX", "..X", "XXX", "XXX", "X.X", "XXX", "XXX", "XXX", "XXX", "XXX",
    "X.X", "..X", "..X", "..X", "X.X", "X..", "X..", "..X", "X.X", "X.X",
    "X.X", "..X", "XXX", "XXX", "XXX", "XXX", "XXX", "..X", "XXX", "XXX",
    "X.X", "..X", "X..", "..X", "..X", "..X", "X.X", "..X", "X.X", "..X",
    "XXX", "..X", "XXX", "XXX", "..X", "XXX", "XXX", "..X", "XXX", "XXX"};
int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> s[i];
    }
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < n; j++)
        {
            int a = s[j] - '0';
            if (j!=n-1)
                cout << k[i][a] << ".";
            else
                cout << k[i][a];
        }
        cout << endl;
    }
    return 0;
}