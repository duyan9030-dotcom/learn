#include <bits/stdc++.h>
using namespace std;
int main()
{
    int x, y;
    cin >> x >> y;
    vector<int> year;
    for (int i = x; i <= y; i++)
        if (i % 4 == 0 && i % 100 != 0 || i % 400 == 0)
            year.push_back(i);
    cout << year.size() << endl;
    if (year.size() != 0)
        for (int i = 0; i < year.size(); i++)
        {
            cout << year[i]<<" ";
        }
    return 0;
}