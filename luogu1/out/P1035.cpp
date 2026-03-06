#include<iostream>
using namespace std;
int main()
{
    int k = 0;
    cin >> k;
    double s = 0;
    int n = 0;
    while(s<=k)
    {
        s+=1.0/(n+1);
        n++;
    }
    cout << n;
    return 0;
}