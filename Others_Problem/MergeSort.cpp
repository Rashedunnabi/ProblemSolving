#include <bits/stdc++.h>
#define Faster ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
using namespace std;

const int N = 1e5 + 7;
int arr[N], temp[N];

void merge(int arr[], int lo, int mid, int hi)
{
    int i = lo, j = mid + 1, k = lo;
    while (i <= mid && j <= hi)
    {
        if (arr[i] <= arr[j])
        {
            temp[k++] = arr[i++];
        }
        else
        {
            temp[k++] = arr[j++];
        }
    }
    while (i <= mid)
        temp[k++] = arr[i++];
    while (j <= hi)
        temp[k++] = arr[j++];

    for (int i = lo; i <= hi; i++)
        arr[i] = temp[i];
}

void mergeSort(int arr[], int lo, int hi)
{
    if (lo >= hi)
        return;
    int mid = (lo + hi) / 2;
    mergeSort(arr, lo, mid);
    mergeSort(arr, mid + 1, hi);
    merge(arr, lo, mid, hi);
}
int main()
{
    Faster;
    int n, i;
    cin >> n;
    for (i = 0; i < n; i++)
        cin >> arr[i];

    mergeSort(arr, 0, n - 1);

    for (i = 0; i < n; i++)
        cout << arr[i] << ' ';
    cout << '\n';

    return 0;
}