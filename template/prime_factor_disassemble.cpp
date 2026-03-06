#include <bits/stdc++.h>
using namespace std;
void f(int n)
{
    for (int i = 2; i * i < n; i++)
    {
        if (n % i == 0)
        {
            cout << i << endl;
            while(n%i==0)
                n /= i;
        }
    }
    if(n>1)
        cout << n;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    f(n);
}