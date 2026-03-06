#include<iostream>
#include<algorithm>
using namespace std;
int main()
{
    int n;
    cin>>n;
    int m = 10000000;
    for (int i = 0; i < 3;i++)
    {
        int a, b;
        cin >> a >> b;
        int num = (n + a - 1) / a;
        m = min(m, num*b);
    }
    cout << m;
    return 0;
}