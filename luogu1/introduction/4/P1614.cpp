#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n, m;
    cin >> n >> m;
    int k = 10000000;
    vector<int> s(n, 0);
    for (int i = 0; i < n; i++)
        cin >> s[i];
    for (int i = 0; i <= n-m; i++)
    {
        int sum = 0;
        for (int j = i; j < i + m; j++)
        {

            sum += s[j];
        }
        k = min(k, sum);
    }
    cout << k;
    return 0;
}