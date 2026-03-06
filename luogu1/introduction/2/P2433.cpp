#include <bits/stdc++.h>
using namespace std;
#define PI 3.141593
int main()
{
    int n;
    cin >> n;
    switch (n)
    {
    case 1:
       {
           cout << "I love Luogu!";
           break;
       }
    case 2:
        {
            cout << 6 << " " << 4;
            break;
        }
    case 3:
        {
            cout << 3 << "\n" << 12 << "\n" << 2;
            break;
        }
    case 4:
       {
           cout << 166.667;
           break;
       }
    case 5:
        {
            cout << (260 + 220) / (12 + 20);
            break;
        }
    case 6:
      {
          cout << sqrt(6 * 6 + 9 * 9);
          break;
      }
    case 7:
        {
            cout << 110 << "\n" << 90 << "\n" << 0;
            break;
        }
    case 8:
       {
           cout <<10 * 3.141593 << "\n" <<  3.141593 * 25 << "\n" << 125 * 3.141593 * 4 / 3;
           break;
       }
    case 9:
       {
           cout << 22;
           break;
       }
    case 10:
        {
            cout << 9;
            break;
        }
    case 11:
       {
           cout << 100.0 / 3;
           break;
       }
    case 12:
       {
           cout <<13<<"R";
           break;
       }
    case 13:
       {
           double V1 = 4 * PI * 64 / 3.0, V2 = 4 * PI * 1000 / 3.0;
           cout << (int)pow(V1 + V2, 1 / 3.0);
           break;
       }
    case 14:
       {
           cout << 50;
           break;
       }
    default:
        break;
    }
    return 0;
}
