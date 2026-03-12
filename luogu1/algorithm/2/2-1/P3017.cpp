#include <bits/stdc++.h>
using namespace std;
typedef __int128 int128;
#define ll long long
const int mod = 1e9 + 7;
int s[505][505];
int row, col, a, b, v;
int getsum(int r1,int c1,int r2,int c2)
{
    return s[r2][c2] - s[r1 - 1][c2] - s[r2][c1 - 1] + s[r1 - 1][c1 - 1];
}
bool check(int mid)
{
    int rd = 0;
    int prer = 0;
    for (int i = 1; i <= row;i++)
    {
        int cf = 0;
        int prec = 0;
        for (int j = 1; j <= col;j++)
        {
            if(getsum(prer+1,prec+1,i,j)>=mid)
            {
                cf++;
                prec = j;
            }
        }
        if(cf>=b)
        {
            rd++;
            prer = i;
        }
    }
    return rd >= a;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> row >> col >> a >> b;
    for (int i = 1; i <= row; i++)
    {
        for (int j = 1; j <= col; j++)
        {
            cin >> v;
            s[i][j] = s[i - 1][j] + s[i][j - 1] - s[i - 1][j - 1] + v;
        }
    }
    int l = 0, r = s[row][col], ans = 0;
    while(l<=r)
    {
        int mid = l + (r - l) / 2;
        if(check(mid))
        {
            ans = mid;
            l = mid + 1;
        }
        else{
            r = mid - 1;
        }
    }
    cout << ans << endl;
    // 怎么切使得每一块差值最小
}