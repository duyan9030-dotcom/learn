#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin >> n;
    int x;
    cin>>x;
    int m = x;
    for (int i = 1;i<n;i++)
    {
        cin>>x;
        m = min(m, x);
    }
    cout << m;
    return 0;
}
