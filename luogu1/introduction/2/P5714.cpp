#include <bits/stdc++.h>
using namespace std;
int main()
{
    double m,h;
    cin>>m>>h;
    double bmi = m / (h * h);
    if(bmi<18.5)
    {
        cout << "Underweight";
    }
    if(bmi>=18.5&&bmi<24)
    {
        cout << "Normal";
    }
    if(bmi>=24)
    {
        cout << bmi << endl
             << "Overweight";
    }
    return 0;
}