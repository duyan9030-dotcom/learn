#include <bits/stdc++.h>
using namespace std;
int main()
{
    int M, N;
    long long s[10] = {0};
    cin >> M >> N;
    for (int i = M; i <= N;i++)
    {
        int b,k=i;
        while (k != 0)
        {
            b = k % 10;
            s[b] = s[b] + 1;
            k /= 10;
        }
    }
    for (int i = 0; i < 10;i++)
    {
        cout << s[i] << " ";
    }
        return 0;
}