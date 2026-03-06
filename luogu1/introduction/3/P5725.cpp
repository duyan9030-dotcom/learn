#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n, a = 1;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (a< 10)
                cout << "0" << a;
            else
            {
                cout << a;
            }
            a++;
        }
        cout << endl;
    }
    cout << endl;
    a = 1;
    for (int i = 1; i <= n;i++)
    {
        for (int j = n * 2 -i*2 ; j > 0; j--)
        {
            cout << " ";
        }
        for (int k = 0; k < i;k++)
        {
            if(a<10)
                cout << "0" << a;
            else
                cout << a;
            a++;
        }
        cout << endl;
    }
        return 0;
}