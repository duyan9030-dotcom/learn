#include <bits/stdc++.h>
using namespace std;
int s[15][15] = {0};
int main()
{
    int n;
    cin >> n;
    int x = 1, y = 1;
    s[x][y] = 1;
    for (int i = 2; i <= n * n; i++)
    {
        if(s[x][y+1]==0&&y+1<=n&&(s[x-1][y]!=0||x-1<=1))//右
            y++;
        else if(s[x+1][y]==0&&x+1<=n)//下
            x++;
        else if(s[x][y-1]==0&&y-1>=1)//左
            y--;
        else
            x--;
        s[x][y] = i;
    }
    for (int i = 1; i <= n;i++)
    {
        for (int j = 1; j <= n;j++)
        {
            if(s[i][j]<10)
            cout <<"  "<< s[i][j];
            else
                cout <<" "<<s[i][j];
        }
        cout << endl;
    }
        return 0;
}