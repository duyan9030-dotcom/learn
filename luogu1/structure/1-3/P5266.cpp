#include <bits/stdc++.h>
using namespace std;
int main()
{
    int q, op;
    cin >> q;
    unordered_map<string, int> map;
    while (q--)
    {
        cin >> op;
        if (op == 1)
        {
            string name;
            cin >> name;
            int score;
            cin >> score;
            map[name] = score;
            cout << "OK" << endl;
        }
        else if (op == 2)
        {
            string name;
            cin >> name;
            if (map.find(name) != map.end())
                cout << map[name] << endl;
            else
                cout << "Not found" << endl;
        }
        else if (op == 3)
        {
            string name;
            cin >> name;
            if (map.find(name) != map.end())
            {
                map.erase(name);
                cout << "Deleted successfully" << endl;
            }
            else
            {
                cout << "Not found" << endl;
            }
        }
        else
        {
            cout << map.size()<<endl;
        }
    }
    return 0;
}