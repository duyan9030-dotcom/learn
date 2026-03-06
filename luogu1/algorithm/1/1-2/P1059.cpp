#include <bits/stdc++.h>
using namespace std;
int a[1005]={0};
int main()
{
    int n,x,m=0;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> x;
        a[x]++;
        if(a[x]==1)
            m++;
    }
    cout << m << endl;
    for (int i = 0; i <=1000;i++)//为什么把
        if(a[i]!=0)
            cout << i<<" ";
            
        return 0;
}