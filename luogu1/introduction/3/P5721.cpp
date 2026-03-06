#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin>>n;
    int k = 1;
    for (int i = n; i >0;i--)
    {
        for (int j = 0; j < i;j++)
        {
            if(k<10)
            {
                cout << "0" << k;
            }
            else{
                cout << k;
            }
            k++;
        }
        cout << endl;
    }
        return 0;
}
