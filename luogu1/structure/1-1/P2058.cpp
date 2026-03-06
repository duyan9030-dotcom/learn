#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n, sum = 0;
    queue<pair<int, int>> q;
    int num[300005];
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        long long t, k;
        cin >> t >> k;
        for (int j = 0; j < k; j++)
        {
            int a;
            cin >> a;
            q.push({a, t});
            if (num[a] == 0)
                sum++;
            num[a]++;
        }
        while (t - q.front().second >= 86400)
        {
            //cout << t - q.front().second << endl;
            if (num[q.front().first] == 1)
                sum--;
            num[q.front().first]--;
            q.pop();
        }
        cout << sum << endl;
    }
}