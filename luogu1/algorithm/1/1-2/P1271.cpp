#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n, m;
    cin >> n >> m;
    vector<int> mk;
    int a;
    for (int i = 0; i < m; i++)
    {
        cin >> a;
        mk.push_back(a);
    }
    sort(mk.begin(), mk.end());
    for (int i = 0; i < m; i++)
        cout << mk[i] << " ";
    return 0;
}