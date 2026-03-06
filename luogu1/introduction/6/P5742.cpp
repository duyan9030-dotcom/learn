#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n,x,t;
    cin >> n;
    vector<bool> g(n, 0);
    string s;
    for (int i = 0; i < n; i++)
    {
        cin >> s >> x >> t;
        if (x*7+t*3>=800&&x+t>140)
            g[i] = 1;
    }
    for (int i = 0; i < n; i++)
        if (g[i])
            cout << "Excellent" << endl;
        else
            cout << "Not excellent" << endl;
    return 0;
}