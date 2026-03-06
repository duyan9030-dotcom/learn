#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin >> n;
    char c;
    for (int i = 0; i < n;i++)
    {
        string a;
        cin >> a;
        int x = 0, y;
        if(a[0]>='0'&&a[0]<='9')
        {
            int len = a.size();
            for (int j = 0; j < len;j++)
            {
                x *= 10;
                x += a[j] - '0';
            }
        }
        else{
            c = a[0];
            cin >> x;
        }
        cin >> y;
        int x1 = x, y1 = y, len1 = 0, len2 = 0;
        if(x1==0)
            len1 = 1;
        while(x1!=0)
        {
            len1++;
            x1 /= 10;
        }
        if(y1==0)
            len2 = 1;
        while(y1!=0)
        {
            len2++;
            y1 /= 10;
        }
        if(c=='a'){
            int z = x + y, z1 = z, len3 = 0;
            if(z1==0)
                len3 = 1;
            while (z1!=0)
            {
                len3++;
                z1 /= 10;
            }
            printf("%d+%d=%d\n%d\n", x, y, z, len1 + len2 + len3+2);
        }else if(c=='b')
        {
            int z = x - y, z1 = z, len3 = 0;
            if (z1 <= 0)
                len3 = 1;
            while (z1 != 0)
            {
                len3++;
                z1 /= 10;
            }
            printf("%d-%d=%d\n%d\n", x, y, z, len1 + len2 + len3+2);
        }
        else{
            int z = x * y, z1 = z, len3 = 0;
            if (z1 == 0)
                len3 = 1;
            while (z1 != 0)
            {
                len3++;
                z1 /= 10;
            }
            printf("%d*%d=%d\n%d\n", x, y, z, len1 + len2 + len3 + 2);
        }
    }
        return 0;
}