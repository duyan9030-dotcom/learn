#include <bits/stdc++.h>
using namespace std;
int main()
{
    int N, x,sum=0,s=0;
    cin >> N;
    while(cin>>x)
    {
        for (int i = 0; i < x;i++)
        {
            cout << s;
            sum++;
            if(sum%N==0)
                cout << endl;
        }
        s = s == 0 ? 1 : 0;
    }
    return 0;
}