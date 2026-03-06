#include <iostream>
using namespace std;
int main()
{
    int m = 0;
    int x = 0;
    int p = 0;
    for (int i = 1; i <= 12; i++)
    {
        cin >> p;
        m = m + 300 - p;
        if (m < 0)
        {
            cout << "-" << i;
            return 0;
        }
        while (m >= 100)
        {
            x += 100;
            m -= 100;
        }
    }
    cout << x * 1.2 + m;
    return 0;
}