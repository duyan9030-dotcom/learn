#include<iostream>
using namespace std;
int ok = 0;
int i = 0;
char a;
int main()
{
    
    for (;;i++)
    {
        cin >> a;
        if(a==')'&&i==0) 
        {
            cout << "NO";
            return 0;
        }
        if(a=='(')
            ok++;
        if(a==')')
            ok--;
        if(ok<0)
        {
            cout << "NO";
            return 0;
        }
        if(a=='@')
        {
            if(!ok)
                cout << "YES";
            else
                cout << "NO";
            return 0;
        }
    }
}
