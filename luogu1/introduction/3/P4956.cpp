#include <bits/stdc++.h>
using namespace std;
int main()
{
    int N,n;
    cin >> N;
    n = N /(7*52);
    int X=0, K=n;
    for (int i = 1; i < n;i++)
    {
        for (int j = 1; j < n;j++)
        {
            if(i+3*j==n&&i<=100)
            {
                X = max(X, i);
                K = min(K, j);
            }
        }
    }
    cout << X << endl
         << K;
    return 0;
}
