#include <bits/stdc++.h>
using namespace std;
int a[2000001];
int main()
{
    int n, m,sum;
    cin >> n >> m;
    for (int i = 1; i <= n;i++)
        cin >> a[i];
    for (int i = 1; i <= m;i++)
    {
        cin >> sum;
        cout << a[sum] << endl;
    }
}