#include<bits/stdc++.h>
using namespace std;
int main()
{
    vector<int> a;
    int x=1;
    while(cin>>x)//使用了cin特性，输入直到EOF
    {
        a.push_back(x);
    }
    a.pop_back();//弹出末尾0
    for (int i = a.size()-1;i>=0;i--)
        cout << a[i] << " ";
    return 0;
}