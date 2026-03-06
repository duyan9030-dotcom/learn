#include <bits/stdc++.h>
using namespace std;
int main()
{
    int a[3];
    cin >> a[0] >> a[1] >> a[2];
    sort(a, a + 3);
    char b[3];
    cin >> b[0] >> b[1] >> b[2];
    for (int i = 0; i < 3; i++)
    {
        switch (b[i])
        {
        case 'A':
            cout << a[0] << " ";
            break;
        case 'B':
            cout << a[1] << " ";
            break;
        case 'C':
            cout << a[2] << " ";
            break;
        default:
            break;
        }
    }
    return 0;
}