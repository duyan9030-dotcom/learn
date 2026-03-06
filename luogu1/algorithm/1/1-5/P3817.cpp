#include <bits/stdc++.h>
using namespace std;
int main()
{

    
    int n, x;
    long long sum=0;
    cin >> n >> x;
    vector<long long> plate(n+1);
    for (int i = 0; i < n; i++)
        cin >> plate[i];
    for (int i = 0; i < n; i++)
    {
        if (plate[i] + plate[i + 1] > x)
        {
            sum += plate[i] + plate[i + 1] - x;
            plate[i + 1] =x-plate[i];
        }
    }
    cout << sum;
}