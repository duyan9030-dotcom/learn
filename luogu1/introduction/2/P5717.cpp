#include <bits/stdc++.h>
using namespace std;
bool n(int a[])
{
    return (a[0] + a[1] <= a[2]);//两边之和必然大于第三边
}
bool r(int a[])
{
    return (a[0] * a[0] + a[1] * a[1] == a[2] * a[2]);
}
bool actue(int a[])
{
    return (a[0] * a[0] + a[1] * a[1] > a[2] * a[2]);
}
bool o(int a[])
{
    return (a[0] * a[0] + a[1] * a[1] < a[2] * a[2]);
}
bool i(int a[])
{
    return (a[0] == a[1] || a[1] == a[2]);
}
bool e(int a[])
{
    return a[0] == a[1] && a[1] == a[2];
}
int main()
{
    int a[3];
    cin >> a[0] >> a[1] >> a[2];
    sort(a, a + 3);
    if (n(a))
    {
        cout << "Not triangle" << endl;
        return 0;
    }
    if (r(a))
    {
        cout << "Right triangle" << endl;
    }
    if (actue(a))
    {
        cout << "Acute triangle" << endl;
    }
    if (o(a))
    {
        cout << "Obtuse triangle" << endl;
    }
    if (i(a))
    {
        cout << "Isosceles triangle" << endl;
    }
    if (e(a))
    {
        cout << "Equilateral triangle" << endl;
    }

    return 0;
}