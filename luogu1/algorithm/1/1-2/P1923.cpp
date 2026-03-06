#include <bits/stdc++.h>
using namespace std;
long long n, k;
long long a[5000005];
void dfs(long long l,long long r)
{
    if(l>r)
        return;
    long long num = a[l];
    vector<long long> maxn, minn;
    for (int i = l+1; i <= r;i++)
    {
        if(a[i]<num)
            minn.push_back(a[i]);
        else
            maxn.push_back(a[i]);
    }
    for (int i = l; i < l + minn.size();i++)
        a[i] = minn[i - l];
    a[l + minn.size()] = num;
    for (int i = l + minn.size() + 1; i <= r;i++)
        a[i] = maxn[i - l - minn.size() - 1];
    if(k<minn.size()+1)
        dfs(l, l + minn.size() - 1);
    else if(k==minn.size()+1)
    {
        cout << num;
        exit(0);
    }
    else{
        k -= minn.size() + 1;
        dfs(l + minn.size() + 1, r);
    }
}
int main()
{

    scanf("%lld %lld", &n, &k);
    for (int i = 1; i <= n; i++)
        scanf("%lld", &a[i]);
    k += 1;
    dfs(1, n);
    return 0;
}