#include <bits/stdc++.h>
using namespace std;
long long sum = 0;
int n, l = 0;
int main()
{
    while (cin >> n)
        sum += n, l++;
    cout << sum *(long long) pow(2, l - 1);
    return 0;
}
