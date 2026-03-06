#include <bits/stdc++.h>
using namespace std;
main()
{
    int n;
    cin >> n;
    vector<int> h(n);
    for (int &a : h)
        cin >> a;
    sort(h.begin(), h.end());
    int now = n - 1, l = 0, r = n - 1, temp = 0; // 当前的石头，和没有跳过的最低的石头
    long long sum = h[n - 1] * h[n - 1];
    while (temp != n - 1)
    {
        sum += (h[now] - h[temp % 2 ?r:l]) * (h[now] - h[temp % 2 ? r:l]);
        if (temp % 2)
        {
            now = r;
            l++;
        }
        else
        {
            now = l;
            r--;
        }
        temp++;
    }
    cout << sum;
}