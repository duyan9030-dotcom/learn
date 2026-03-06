#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n, b;
    cin >> n >> b;
    vector<int> h;
    for (int i = 0; i < n;i++)
    {
        int x;
        
        cin >> x;
        h.push_back(x);
    }
    sort(h.begin(), h.end());
    int sum = 0;
    for (int i = n - 1; i >= 0;i--)
    {
        b -= h[i];
        sum++;
        if(b<=0)
            break;
    }
    cout << sum;
    return 0;
}