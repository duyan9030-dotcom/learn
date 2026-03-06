#include <bits/stdc++.h>
using namespace std;
int q[105];
int n, l, r, vo;
void output()
{
    for (int i = 1; i <= 2 * n + 2; i++)
    {
        if (q[i] == 0)
            cout << "o";
        else if (q[i] == 1)
            cout << "*";
        else
            cout << "-";
    }
    cout << endl;
}
void f(int x)
{
    if (x > 4)
    {
        swap(q[vo], q[r / 2]);
        swap(q[vo + 1], q[r / 2 + 1]);
        vo = r / 2;
        output();
        swap(q[vo], q[r - 1]);
        swap(q[vo + 1], q[r]);
        r = r - 2;
        vo = r + 1;
        output();
        f(x - 1);
    }
    else if (x == 4)
    {
        swap(q[vo], q[r / 2]);
        swap(q[vo + 1], q[r / 2 + 1]);
        vo = r / 2;
        output();
        swap(q[vo], q[r]);
        swap(q[vo + 1], q[r + 1]);
        output();
        vo = r;
        r -= 1;
        swap(q[vo], q[l + 1]);
        swap(q[vo + 1], q[l + 2]);
        output();
        vo = l + 1;
        swap(q[vo], q[r]);
        swap(q[vo + 1], q[r + 1]);
        vo = r;
        r -= 1;
        output();
        swap(q[vo], q[l]);
        swap(q[vo + 1], q[l + 1]);
        output();
    }
}
int main()
{

    cin >> n;
    q[0] = 1;
    for (int i = n + 1; i <= 2 * n; i++)
        q[i] = 1;
    q[2 * n + 1] = q[2 * n + 2] = -1;
    l = 1, r = 2 * n, vo = 2 * n + 1;
    output();
    f(n);
}