#include <bits/stdc++.h>
using namespace std;
void QuickSort(vector<int> &arr, int left, int right)
{
    if (left >= right)
        return;
    int f;
    int rtemp, ltemp;//
    ltemp = left;
    rtemp = right;
    f = arr[(left + right) / 2];
    while (ltemp <= rtemp)
    {
        while (arr[ltemp] < f)
        {
            ++ltemp;
        }
        while (arr[rtemp] > f)
        {
            --rtemp;
        }
        if (ltemp <= rtemp)
        {
            swap(arr[ltemp], arr[rtemp]); 
            ++ltemp;
        }
    }
    if (left < rtemp)
    {
        QuickSort(arr, left, rtemp);
    }
    if (ltemp < right)
    {
        QuickSort(arr, ltemp, right);
    }
}

int main()
{
    int n, x;
    cin >> n;
    vector<int> a;
    for (int i = 0; i < n; i++)
    {
        cin >> x;
        //a.push_back(x);
    }
    //QuickSort(a,0, n-1);
    for (int i = 0; i < n; i++)
        cout << a[i] << " ";
    return 0;
}