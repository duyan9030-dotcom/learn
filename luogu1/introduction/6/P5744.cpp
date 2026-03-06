#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin >> n;
    vector<string> name(n);
    vector<vector<float>> yc;
    for (int i = 0; i < n; i++)
    {
        cin >> name[i];
        float a, b;
        cin >> a >> b;
        yc.push_back({a, b});
    }
    for (int i = 0; i < n; i++)
    {
        if (yc[i][1] * 1.2 > 600)
            cout << name[i] << " " << yc[i][0] + 1 << " " << 600;
        else
            cout << name[i] << " " << yc[i][0] + 1 << " " << (int)yc[i][1] * 1.2;
        cout << endl;
    }
    return 0;
}
