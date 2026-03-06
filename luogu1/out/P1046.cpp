#include <bits/stdc++.h>
using namespace std;
int main()
{
    vector<int> h(10);
    for (int i = 0; i < 10; i++)
        cin >> h[i];
    int x;
    cin >> x;
    int num = 0;
    for (int i = 0; i < 10; i++)
    {
        if (x + 30 >= h[i])
            num++;
    }
    cout<<num;
    return 0;
}