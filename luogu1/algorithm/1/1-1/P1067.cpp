#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin >> n;
    for (int i = n; i >= 0; i--)
     {
         int an;
         cin >> an;
         if(an)//如果为0，直接退出
         {
            if(i!=n&&an>0)
                cout << "+";
            if(i!=0&&an==-1)
                cout << "-";
            if(abs(an)>1||i==0)
                cout << an;
            if(i>1)
                cout << "x^" << i;
            if(i==1)
                cout << "x";
         }
     }
    return 0;
}
