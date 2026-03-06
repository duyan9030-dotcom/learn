//等差数列差分
// 1  2  3  4  5  6  7  8  9  10
//0  1  1  1  1  1  1  1  1  1
//    0  0  0  0  0  0   0  0
#include <bits/stdc++.h>
using namespace std;
#define offset 30001
int n, m;
int arr[1060005];
void setting(int l, int r, int s, int e, int d)
{
    arr[l + offset] += s;
    arr[l + 1 + offset] += d - s;
    arr[r + 1 + offset] -= d + e;
    arr[r + 2 + offset] += e;
}
void fall(int v, int x)
{
    setting(x - 3 * v+1, x - 2 * v, 1, v, 1);
    setting(x - 2 * v + 1, x, v - 1, -v, -1);
    setting(x + 1, x + 2 * v, 1 - v, v, 1);
    setting(x + 2 * v + 1, x + 3 * v-1, v - 1, 1, -1);
}
void build()
{
    for (int i = 1; i <= m+offset; i++)
        arr[i] += arr[i - 1];
    for (int i = 1; i <= m+offset; i++)
        arr[i] += arr[i - 1];
}
int main()
{
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        int v, x;
        cin >> v >> x;
        fall(v, x);
    }
    build();
    int start = offset + 1;
    for (int i = 1; i <= m; i++)
    {
        cout << arr[start++] << " ";
    }
}