#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin>>n;
    if(n<=1)
    {
        cout << "Today, I ate" << " " << n << " " << "apple.";
    }
    if(n>1)
    {
        cout << "Today, I ate" <<" "<< n <<" "<< "apples.";
    }
    return 0;
}
