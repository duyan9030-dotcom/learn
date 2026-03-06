#include <bits/stdc++.h>
using namespace std;
int main()
{
    string a, b;
    cin >> a;
    int n = a.size(), c = 1;
    while (c < n)
    {
        cin >> b;
        a+=b;
        c++;
    }
    cout << n<<" ";
    if(a[0]!='0')
        cout << 0<<" ";
    int cnt = 1;
    char s=a[0];
    for (int i = 1; i < a.size();i++)
    {
        if(s==a[i])
            cnt++;
        else{
            cout << cnt << " ";
            cnt = 1;
        }
        s = a[i];
    }
    cout << cnt;
    return 0;
}
