#include <bits/stdc++.h>
using namespace std;
class p
{
public:
    int t;
    int x;
};
bool cmp(p p1, p p2)
{
    if (p1.t != p2.t)
        return p1.t < p2.t;
    return p1.x < p2.x;
}
int main()
{
    int n;
    cin >> n;
    vector<p> q(n);

    for (int i = 0; i < n; i++)
    {
        cin >> q[i].t;
        q[i].x = i;
    }
    sort(q.begin(), q.end(), cmp);
    double avg = 0;
    for (int i = 0; i < n; i++)
        cout << q[i].x + 1 << " ";
    cout << endl;
    for (int i = 1; i < n; i++)
        for (int j = 0; j < i;j++)
            avg += q[j].t;
    printf("%.2lf", avg / n);
}