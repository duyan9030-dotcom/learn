#include <bits/stdc++.h>
using namespace std;
int h(int n)
{
    int a = 0;
    while(n!=0)
    {
        a = a*10+n % 10;
        n /= 10;
    }
    return a;
}
bool z(int n)
{
    for (int i = 2; i * i <= n;i++)
    {
        if(n%i==0)
            return false;
    }
    return true;
}
int main()
{
    int a, b;
    cin >> a >> b;
    for (int i = a; i <= b;i++)
    {
        if(i%2!=0)
        {
            if (i == h(i))
            {
                if (z(i))
                {
                    cout << i << endl;
                }
            }
        }
    }
        return 0;
}