#include <bits/stdc++.h>
using namespace std;
int a[10];
int n;
void dfs(int sum,int k,int next)
{
    if(sum==n)
    {
        for (int i = 1; i <= k-2;i++)
            cout << a[i] << "+";
        cout << a[k-1]<<endl;
        return;
    }
    if(sum>n)
        return;
    for (int i = next; i <= n-1; i++)
    {
        a[k] = i;
        dfs(sum+i, k + 1,i);
        a[k] = 0;
    }
}
int main()
{
    cin >> n;
    dfs(0,1,1);
}