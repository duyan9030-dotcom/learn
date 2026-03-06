#include <bits/stdc++.h>
using namespace std;
int k[30] = {0};
bool z(int a)
{
    if(a==1||a==0)
        return false;
    for (int i = 2; i * i <= a;i++)
    {
        if(a%i==0)
            return false;
    }
    return true;
}
int main()
{
    string s;
    cin >> s;
    for (int i = 0; i < s.size();i++)
    {
        k[s[i] - 'a'+1]++;
    }
    int maxn = -10000, minn = 10000;
    for (int i = 1; i <= 26;i++)
    {
        if(k[i]==0) continue;
        maxn = max(maxn, k[i]);
        minn = min(minn, k[i]);
    }
    if(z(maxn-minn))
        cout << "Lucky Word"<<endl<<maxn-minn;
    else
        cout << "No Answer"<<endl<<0;
    
        return 0;
}