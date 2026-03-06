#include <bits/stdc++.h>
using namespace std;
struct p
{
public:
    int a;
    int b;
};
bool cmp(p x, p y)
{
    return x.b < y.b;
}
int main()
{
    int n;
    cin >> n;
    vector<p> s(n);
    for (int i = 0; i < n; i++)
        cin >> s[i].a >> s[i].b;
    sort(s.begin(), s.end(), cmp);
    int sum = 1;
    int t = s[0].b;

    for (int i = 1; i < n; i++)
    {
        if (s[i].a >= t)
        {
            sum++;
            t = s[i].b;
        }
    }
    cout << sum;
}