#include <bits/stdc++.h>
using namespace std;
long long cnt(long long num, int d)
{
    long long ans = 0;
    long long right = 1, tmp = num, left, cur;
    while (tmp != 0)
    {
        left = tmp / 10;
        cur = tmp % 10;
        if(d==0)
            left--;
        ans += left * right;
        if(cur>d)
            ans += right;
        if(cur==d)
            ans += num % right + 1;
        right *= 10;
        tmp /= 10;

    }
    return ans;
}
int main()
{
    long long a, b;
    cin >> a >> b;
    for (int i = 0; i <= 9; i++)
        cout << cnt(b, i) - cnt(a-1, i) << " ";
    return 0;
}