#include <bits/stdc++.h>
using namespace std;
const int N = 105, M = 2e5 + 5;
int a[N];//接受数
bool f[M];//记录每一个数是否存在，最大和为20000
int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        f[a[i]] = true;
    }
    int h = 0;
    for (int j = 0; j <n; j++)
    {
        for (int k = j + 1; k < n; k++)
        {
            if (f[a[j] + a[k]])//遍历每两个数的和，若f[a[j]+a[k]]==true,即和存在
            {
                h++;
                f[a[j] + a[k]] = false;//
            }
        }

        
    }
    cout<<h;
    return 0;
}