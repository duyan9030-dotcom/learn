#include<bits/stdc++.h>
using namespace std;
int j(int n)
{
    if(n==1||n==0)
        return 1;
    return n*j(n - 1);
}
int main()
{
    int n;
    cin >> n;
    cout << j(n);
    return 0;
}