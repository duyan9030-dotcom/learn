#include <bits/stdc++.h>
using namespace std;
bool at[2000005] = {0};
int main()
{ 
    int n, t;
    double a;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> a >> t;
        for (int j = 1; j <= t; j++)
        {
            int k =(int) (a * j);
            if(k>=0&&k<2000005)
            {
                if (at[k])
                    at[k] = false;
                else
                    at[k] = true;
            }
        }
    }
    for (int i = 0; i < 2000005; i++)
        if (at[i])
            {
                cout << i;
                return 0;
            }
    return 0;
}