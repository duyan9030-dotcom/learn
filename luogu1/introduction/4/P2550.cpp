#include <bits/stdc++.h>
using namespace std;
int s[7];
int j(int* a)
{
    int k = 7;
    for (int i = 0; i < 7;i++)
    {
        for (int j = 0; j < 7;j++)
        {
            if(a[i]==s[j])
            {
                k--;
            }
        }
    }
    return k;
}
int main()
{
    int n;
    cin >> n;
    cin >> s[0] >> s[1] >> s[2] >> s[3] >> s[4] >> s[5] >> s[6];
    int k[7] = {0};
    while(n--)
    {
        int a[7];
        cin >> a[0] >> a[1] >> a[2] >> a[3] >> a[4] >> a[5] >> a[6];
        if(j(a)<7)
            k[j(a)]++;
    }
    for (int i = 0; i < 7;i++)
        cout << k[i] << " ";
        return 0;
}