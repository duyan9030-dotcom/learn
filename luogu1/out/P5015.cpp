#include <bits/stdc++.h>
using namespace std;
int main()
{
    string s;
    getline(cin, s);//可以一口气读取一整行的字符，空格也读但不读换行符
    int n = s.size();
    for(char x:s)
    {
        if(x==' ')
            n--;
    }
    cout << n;
    return 0;

}