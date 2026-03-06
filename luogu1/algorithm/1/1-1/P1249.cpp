#include <bits/stdc++.h>
using namespace std;
vector<int> a;
int cj[10000];
int n, h=0, i;
void jc()
{
    cj[0] = 1;
    for (int i = 0; i < a.size(); i++)
        if (a[i] != 0)
        {
            for (int j = 0; j < 10000; j++)
                cj[j] *= a[i];
            for (int j = 0; j < 10000; j++)
                if (cj[j] >= 10)
                {
                    cj[j + 1] += cj[j] / 10;
                    cj[j] %= 10;
                }
        }
}
int main()
{
    cin >> n;
    if (n <= 4)
    {
        cout << n << endl
             << n;
        return 0;
    }
    if(n==8)
    {
        cout << 3 << " " << 5 << endl
             << 15;
        return 0;
    }
    for (i = 2; i <= n; i++)
    {
        h += i;
        a.push_back(i);
        if (h > n)
            break;
    }
    for (i = 2; i <n; i++)
        if (h - i == n)
            for (int j = a.size()-1; j >=0; j--)
                if (a[j] == i)
                {
                    a[j] = 0;
                    break;
                }
    for ( i = 0; i < a.size(); i++)
        if (a[i] != 0)
            cout << a[i] << " ";
    cout << endl;
    jc();
    int head = 9999;
    while (cj[head] == 0)
        head--;
    for (; head >= 0; head--)
        cout << cj[head];
    return 0;
}