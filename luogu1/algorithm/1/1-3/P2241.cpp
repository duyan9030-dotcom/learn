#include <bits/stdc++.h>
using namespace std;
int main()
{
    long long n, m;
    cin >> n >> m;
    long long z = 0, c = 0;
    for (int i = n, j = m; i > 0 && j > 0; i--, j--)//正方形数量==长宽+(长-1)*(宽-1)......(a>0&&b>0)
        z += i * j;
    c = (n * (n + 1) / 2) * (m * (m + 1) / 2) - z;//矩形数量-正方形数量
    cout << z << " " << c;
    return 0;
}