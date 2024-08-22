#include <bits/stdc++.h>
#define Faster ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
using namespace std;

const int N = 1e5 + 7;
int arr[N], temp[N];

void merge(int arr[], int low, int mid, int high)
{
    int i = low, j = mid + 1, k = low;
    while (i <= mid && j <= high)
    {
        if (arr[i] <= arr[j])
            temp[k++] = arr[i++];

        else
            temp[k++] = arr[j++];
    }

    while (i <= mid)
        temp[k++] = arr[i++];

    while (j <= high)
        temp[k++] = arr[j++];

    for (int i = low; i <= high; i++)
        arr[i] = temp[i];
}

void mergeSort(int arr[], int low, int high)
{
    if (low >= high)
        return;
    int mid = (low + high) / 2;
    mergeSort(arr, low, mid);
    mergeSort(arr, mid + 1, high);
    merge(arr, low, mid, high);
}
int main()
{
    Faster;
    int n, i;
    cin >> n;
    for (i = 0; i < n; i++)
        cin >> arr[i];

    mergeSort(arr, 0, n - 1); // close bound [0,n-1]

    for (i = 0; i < n; i++)
        cout << arr[i] << ' ';
    cout << '\n';

    return 0;
}