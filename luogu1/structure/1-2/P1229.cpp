#include <bits/stdc++.h>
using namespace std;
bool ok(char a, char b, string h)
{
    for (int i = 0; i < h.size() - 1; i++)
        if (a == h[i + 1] && b == h[i])
            return true;
    return false;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    long long ans = 1;
    int sum = 0;
    string q, h;
    cin >> q >> h;
    for (int i = 0; i < q.size() - 1; i++)
        if (ok(q[i], q[i + 1], h))
            sum++;
    cout << (ans << sum);
}
