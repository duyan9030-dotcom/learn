#include <bits/stdc++.h>
using namespace std;
string figure[30] = {"", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine", "ten", "eleven", "twelve", "thirteen", "fourteen", "fifteen", "sixteen", "seventeen", "eighteen", "nineteen", "twenty", "a", "both", "another", "first", "second", "third"};
int a[30] = {0, 1, 4, 9, 16, 25, 36, 49, 64, 81, 0, 21, 44, 69, 96, 25, 56, 89, 24, 61, 0, 1, 4, 1, 1, 4, 9};
vector<int> ma;
int main()
{
    for (int i = 0; i < 6; i++)
    {
        string s;
        cin >> s;
        for (int j = 1; j <= 26; j++)
            if (s == figure[j])
            {
                ma.push_back(a[j]);
                break;
            }
    }
    if (ma.size() == 0)
    {
        cout << 0;
        return 0;
    }
    sort(ma.begin(), ma.end());
    for (int i = 0; i < ma.size(); i++)
        cout << ma[i];
    for (int i = 0; i < ma.size(); i++)
    {
        if (i != 0 && ma[i] < 10)
            cout << 0;
        cout << ma[i];
    }
    return 0;
}