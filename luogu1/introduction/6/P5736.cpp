#include <bits/stdc++.h>
using namespace std;
bool zhishu(int a)
{
    if (a == 1)
        return false;
    for (int i = 2; i * i <= a; i++)
        if (a % i == 0)
            return false;
    return true;
}
int main()
{
    int n, x;
    cin >> n;
    vector<int> zhi;
    for (int i = 0; i < n; i++)
    {
        cin >> x;
        zhi.push_back(x);
    }
    for (int i = 0; i < zhi.size(); i++)
        if (zhishu(zhi[i]))
            cout << zhi[i] << " ";
    return 0;
}
