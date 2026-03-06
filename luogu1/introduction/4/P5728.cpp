#include <bits/stdc++.h>
using namespace std;
int sum(vector<int> a)
{
    int s = 0;
    for (int i = 0; i <= a.size() - 1; i++)
        s += a[i];
    return s;
}
bool q(vector<int> a, vector<int> b)
{
    for (int i = 0; i < 3; i++)
        if (abs(a[i] - b[i]) > 5)
            return false;
    return true;
}
int main()
{
    int n, x;
    cin >> n;
    vector<vector<int>> a(n,vector<int>(3));
    for (int i = 0; i < n; i++)
    {

        cin >> a[i][0] >> a[i][1] >> a[i][2];
    }
    int d = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i == j)
                continue;
            if (abs(sum(a[i]) - sum(a[j])) <= 10 && q(a[i], a[j]))
            {
                d++;
            }
        }
    }
    cout << d / 2;
    return 0;
}