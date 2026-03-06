#include<bits/stdc++.h>
using namespace std;
int num[26] = {1, 2, 3, 1, 2, 3, 1, 2, 3, 1, 2, 3, 1, 2, 3, 1, 2, 3, 4, 1, 2, 3, 1, 2, 3, 4};
int main()
{
    string s;
    int count = 0;
    getline(cin,s);
    for (int i = 0; i < s.size(); i++)
    {
        if(s[i]>='a'&&s[i]<='z')
        count += num[s[i] - 'a'];
        if(s[i]==' ')
            count++;
    }
    cout << count;
    return 0;
}