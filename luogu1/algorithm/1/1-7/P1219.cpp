#include <bits/stdc++.h>
using namespace std;
int n, sum = 0;//n皇后  解的数量
vector<int> record(15);//第i行第record[i]列放了皇后
bool isvalid(int i, int j)
{
    for (int k = 1; k < i; k++)
        if (j == record[k] || abs(record[k] - j) == abs(i - k))
            return false;
    return true;
}
void dfs(int c)
{
    if (c == n + 1)
    {
        sum++;
        if (sum <= 3)
        {
            for (int i = 1; i <= n; i++)
                cout << record[i] << " ";
            cout << endl;
        }
        return;
    }
    for (int i = 1; i <= n; i++)
        if (isvalid(c, i))
        {
            record[c] = i;
            dfs(c + 1);
        }
}
int main()
{
    cin >> n;
    dfs(1);
    cout << sum;
}