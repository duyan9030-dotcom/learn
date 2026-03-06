#include <bits/stdc++.h>
using namespace std;
bool qg(vector<int> a, vector<int> b)
{
    return (abs(a[0] - b[0]) <= 5 && abs(a[1] - b[1]) <= 5 && abs(a[2] - b[2]) <= 5 && abs(b[3] - a[3]) <= 10);
}
int main()
{
    int n;
    cin >> n;
    vector<string> s;
    vector<vector<int>> cj;
    vector<vector<string>> xd;
    for (int i = 0; i < n; i++)
    {
        int a, b, c;
        string m;
        cin >> m;
        cin >> a>> b>>c;
        s.push_back(m);
        cj.push_back({a, b, c, a + b + c});
    }
    for (int i = 0; i < n; i++)
        for (int j = i + 1; j < n; j++)
            if (qg(cj[j], cj[i]))
            {
                xd.push_back({s[i], s[j]});
                sort(xd[xd.size() - 1].begin(), xd[xd.size() - 1].end());
            }
    sort(xd.begin(), xd.end());
    for (int i = 0; i < xd.size(); i++)
    {
        cout << xd[i][0] << " " << xd[i][1] << endl;
    }
    return 0;
}
