#include <bits/stdc++.h>
using namespace std;
int main()
{
    for (int i = 0; i <= 2; i++)
    {
        for (int j = 2; j > i; j--)
            cout << " ";
        for (int j = 0; j < 2 * i + 1; j++)
            cout << "*";
        cout << endl;
    }
    for (int i = 1; i >= 0; i--)
    {
        for (int j = 0; j < 2 - i; j++)
            cout << " ";
        for (int j = 0; j < 2 * i + 1; j++)
            cout << "*";
        cout << endl;
    }
    return 0;
}