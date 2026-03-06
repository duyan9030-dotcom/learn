#include <bits/stdc++.h>
using namespace std;
int main()
{
    long long n, m, maxh = 0,minh=INT_MAX;
    cin >> n >> m;
    vector<long long> h(n);
    for (int i = 0; i < n; i++)
    {
        cin >> h[i];
        maxh = max(maxh, h[i]);
        minh = min(minh, h[i]);
    }
    while (minh<=maxh)
    {
        long long mid = (maxh + minh) / 2;
        long long M = 0;
        for (int i = 0; i < n; i++)
            M += mid < h[i] ? h[i] -mid : 0;
        if(M==m)
        {
            cout << mid;
            return 0;
        }
        if(M<m)
            maxh = mid-1;
        else
            minh = mid+1;
    }
    cout << minh-1;
}