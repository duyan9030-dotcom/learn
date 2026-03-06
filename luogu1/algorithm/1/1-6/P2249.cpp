#include <bits/stdc++.h>
using namespace std;
int n, m;
long long t[1000005], p[100005];
int find(long long k)
{
    int l = 1, r = n;
    int ans = -1;
    while (l <= r)
    {
        int mid = l + (r - l) / 2;//l+r可能溢出
        if (t[mid] < k)
            l = mid + 1;
        else
        {
            if(t[mid]==k)
                ans = mid;
            r = mid - 1;
        }

    }
    return ans;
}
int main()
{
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++)
        scanf("%lld", &t[i]);
    for (int i = 1; i <= m; i++)
        scanf("%lld", &p[i]);
    for (int i = 1; i <= m; i++)
    {
        int index = find(p[i]);
        printf("%d ", index);
    }
}