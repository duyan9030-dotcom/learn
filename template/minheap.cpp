#include <bits/stdc++.h>
using namespace std;
long long heap[10005], size = 0;
void insert(long long a)
{
    heap[size++] = a;
    int i = size - 1;
    while (heap[i] < heap[(i - 1) / 2])
    {
        swap(heap[(i - 1) / 2], heap[i]);
        i = (i - 1) / 2;
    }
}
void update(int i) //
{
    int l = 2 * i + 1;
    while (l < size) // l=1
    {
        int best = l + 1 < size && heap[l + 1] < heap[l] ? l + 1 : l;
        best = heap[best] < heap[i] ? best : i;
        if (best == i)
            break;
        swap(heap[best], heap[i]);
        i = best;
        l = i * 2 + 1;
    }
}
void detop()
{
    if (size == 0)
        return;
    else
    {
        heap[0] == 0;
        swap(heap[0], heap[size - 1]);
        size--;
    }
    update(0);
}