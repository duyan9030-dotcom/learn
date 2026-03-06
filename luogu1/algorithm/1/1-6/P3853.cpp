#include <bits/stdc++.h>
using namespace std;
int main()
{
    int L, N, K, m = 0;
    cin >> L >> N >> K;
    vector<int> flag(N);
    for (int &a : flag)
        cin >> a;
    if(N==2)
    {
        cout << ceil((flag[1] - flag[0]) / 2);
        return 0;
    }
    int l = 0, r = L, mid,ans;
    while (l <= r)
    {
        mid = (l + r) / 2;
        int sum = 0;
        for (int i = 1; i < N; i++)
            if (flag[i] - flag[i - 1] > mid) //比最小的大就需要放路标
                sum += (flag[i] - flag[i - 1] - 1) / mid;
        if (sum <= K)
            r = mid - 1;
        else
            l = mid + 1;
    }
    cout << l;
}