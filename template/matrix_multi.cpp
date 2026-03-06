#include <bits/stdc++.h>
using namespace std;
// 普通矩阵乘法
vector<vector<int>> multi(vector<vector<int>> &a, vector<vector<int>> &b) // a[0].size()必须等于b.size();
{
    int n = a.size();
    int m = b[0].size();
    int k = a[0].size();
    vector<vector<int>> ans(n, vector<int>(m, 0));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            for (int c = 0; c < k; c++)
                ans[i][j] += a[i][c] * b[c][j];
    return ans;
}
// 矩阵快速幂：a必须为正方形矩阵
vector<vector<int>> power(vector<vector<int>> &a, int p)
{
    int n = a.size();
    vector<vector<int>> ans(n, vector<int>(n, 0));
    for (int i = 0; i < n; i++)
        ans[i][i] = 1;
    while (p != 0)
    {
        if (p & 1)
            ans = multi(ans, a);
        a = multi(a, a);
        p >>= 1;
    }
    return ans;
}
// 打印一个矩阵
void printmatrix(vector<vector<int>> a)
{
    for (auto x : a)
    {
        for (auto i : x)
            cout << i << " ";
        cout << endl;
    }
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    vector<vector<int>> a = {{1, 3}, {3, 2}};
    vector<vector<int>> b = {{2, 3, 2}, {3, 2, 3}};
    vector<vector<int>> ans = multi(a, b);
    // printmatrix(ans);
    vector<vector<int>> test = a;
    for (int i = 0; i < 5; i++)
    {
        test = multi(test, a);
    }
    printmatrix(test);
    printmatrix(power(a, 6));
}