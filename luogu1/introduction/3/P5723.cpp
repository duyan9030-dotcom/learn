#include <bits/stdc++.h>
using namespace std;
bool z(int a)
{
    for (int i = 2; i * i <= a; i++)
    {
        if (a % i == 0)
            return false;
    }
    return true;
}
int main()
{
    int L;
    cin >> L;
    int sum = 0, n = 0;
    for (int i = 2; sum + i <= L; i++)
    {
        if (z(i))
        {
            cout << i << endl;
            sum += i;
            n++;
        }
    }
    cout << n << endl;
    return 0;
}
