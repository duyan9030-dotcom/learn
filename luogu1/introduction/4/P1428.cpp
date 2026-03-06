#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin >> n;
    vector<int> a;
    for (int i = 0; i < n;i++)
    {
        int x;
        cin >> x;
        a.push_back(x);
    }
    cout << 0<<" ";
    int s = 0;
    for (int i = 1; i < n;i++)
    {
        for (int j = 0; j < i;j++)
        {
            if(a[j]<a[i])
                s++;
        }
        cout << s << " ";
        s = 0;
    }
        return 0;
}