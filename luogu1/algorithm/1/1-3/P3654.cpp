#include <bits/stdc++.h>
using namespace std;
int main()
{
    int r, c, l;
    cin >> r >> c >> l;
    vector<string> lo(r);
    for (int i = 0; i < r; i++)
        cin >> lo[i];
    int n = 0;
    bool y = 0;
    if (l == 1)
    {
        for (int i = 0; i < r; i++)
        {
            for (int j = 0; j < c; j++)
            {
                if(lo[i][j]=='.')
                    n++;
            }
        }
    }
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j <= c - l; j++)
        {
            if (lo[i][j] == '.')
                for (int k = j + 1; k < j + l; k++)
                {
                    if (lo[i][k] == '#')
                        break;
                    if (k == j + l - 1)
                        y = 1;
                }
            if (y)
            {
                n++;
                y = 0;
            }
        }
    }
    // cout << n;
    for (int i = 0; i < c; i++)
    {
        for (int j = 0; j <= r - l; j++)
        {
            if (lo[j][i] == '.')
                for (int k = j + 1; k < j + l; k++)
                {
                    if (lo[k][i] == '#')
                        break;
                    if (k == j + l - 1)
                        y = 1;
                }
            if (y)
            {
                n++;
                y = 0;
            }
        }
    }
    cout << n;
    return 0;
}
