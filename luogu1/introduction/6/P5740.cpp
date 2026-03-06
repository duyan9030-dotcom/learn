#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n, ma = 0;
    string s;
    int cj[3];
    cin >> n >> s;
    for (int i = 0; i < 3; i++)
    {
        cin >> cj[i];
        ma += cj[i];
    }
    for (int i = 1; i < n; i++)
    {
        string l;
        int cj1[3]={0};
        cin >> l >> cj1[0] >> cj1[1] >> cj1[2];
        int sum = cj1[0] + cj1[1] + cj1[2];
        if (sum > ma)
        {
            s = l;
            cj[0] = cj1[0];
            cj[1] = cj1[1];
            cj[2] = cj1[2];
            ma = sum;
        }
    }
    cout << s << " " << cj[0] << " " << cj[1] << " " << cj[2];
    return 0;
}