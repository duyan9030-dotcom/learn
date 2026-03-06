#include <bits/stdc++.h>
using namespace std;
int main()
{
    int N;
    cin >> N;
    vector<int> c;
    for (int i = 0; i < N; i++)
    {
        int x;
        cin >> x;
        c.push_back(x);
    }
    int sum = 0;
    for (int i = 0; i < N; i++)
    {
        for (int j = i + 1; j < N; j++)
        {
            if (c[i] > c[j])
            {
                swap(c[i], c[j]);
                sum++;
            }
        }
    }
    cout << sum;
    return 0;
}