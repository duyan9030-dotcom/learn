#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n, x;
    cin >> n;
    string s;
    cin >> s;
    for (int i = 0; i < n; i++)
    {
        cin >> x;
        if(x==1)
        {
            string l;
            cin >> l;
            s += l;
            cout << s<<endl;
        }
        else if(x==2)
        {
            int a, b;
            cin >> a >> b;
            s = s.substr(a , b);
            cout << s << endl;
        }
        else if(x==3)
        {
            int a;
            cin >> a;
            string l;
            cin >> l;
            s = s.insert(a , l);
            cout << s << endl;
        }
        else{
            string l;
            cin >> l;
            int x = s.find(l);
            if (x == string::npos)
                cout << -1 << endl;
            else
                cout << x << endl;
        }
    }
    return 0;
}