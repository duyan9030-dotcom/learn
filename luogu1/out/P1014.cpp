// #include <iostream>
// #include<cmath>
// using namespace std;
// int main()
// {
//     int N = 0;
//     cin >> N;
//     int k = 0;
//     for (int i = 2;;i++)
//     {
//         for (int j = 1; j < i;j++)
//         {
//             k++;
//             if(k==N&&i%2==0)
//             {
//                 cout << i-j << "/" << j;
//                 return 0;
//             }
//             else if(k==N&&i%2==1)
//             {
//                 cout << j << "/" << i - j;
//                 return 0;
//             }
//         }
//     }
//     return 0;
// }
#include <iostream>
using namespace std;
int main()
{
    int N = 0, i = 0, j = 0;
    cin >> N;
    while (N > j)
    {
        i++;
        j += i;
    }
    if (i % 2 == 0)
    {
        cout << i +N- j << "/" << j-N+1;
        return 0;
    }
    else
    {
        cout << j - N + 1 << "/" << i + N - j;
        return 0;
    }
}