#include <bits/stdc++.h>
using namespace std;
int s[3000];
int jc(int n)
{
    memset(s, 0, sizeof(s));
    s[0] = 1;
    for (int i = 2; i <= n; i++)
    {
        for (int j = 0; j <= 3000; j++)
            s[j] *= i;
        for (int j = 0; j <= 3000; j++)
            if (s[j] >= 10)
            {
                s[j + 1] += s[j] / 10;
                s[j] %= 10;
            }
    }
    int head = 2999;
    while (s[head--] == 0)
        ;
    return head + 1;
}
int main()
{
    int t;
    cin >> t;
    for (int i = 0; i < t; i++)
    {
        int n, a, x = 0;
        cin >> n >> a;
        int head = jc(n);
        for (int j = 0; j <= head; j++)
            if (s[j] == a)
                x++;
        cout << x << endl;
    }
    return 0;
}