#include <bits/stdc++.h>
using namespace std;
map<int,map<int,int>> b;
int main()
{
    int n, q;
    cin >> n >> q;
    for (int p = 0; p < q;p++)
    {
        int k;
        cin >> k;
        if(k==1)
        {
            int i, j, k;
            cin >> i >> j >> k;
            b[i][j] = k;
        }
        else if(k==2)
        {
            int i, j;
            cin >> i >> j;
            cout << b[i][j] << endl;
        }
    }
}