#include<iostream>
#include<algorithm>
using namespace std;
int main()
{
    int n = 0;
    int ma = 0, j = 0;
    for (int i = 1; i <=7 ;i++)
    {
        int a,b;
        cin >> a >> b;
        if(a+b>8)
        {
            n++;
            j = ma >= a + b ? j : i;
            ma = max(ma, a + b);
        }
    }
    if(n==0)
        cout << 0;
    else
        cout << j;
    return 0;
}