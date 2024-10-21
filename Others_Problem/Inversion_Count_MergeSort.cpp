#include <bits/stdc++.h>
using namespace std;

long long mergeAndCount(long long arr[], int temp[], int left, int mid, int right)
{
    int i = left, j = mid + 1, k = left;
    long long inversions = 0;

    while (i <= mid && j <= right)
    {
        if (arr[i] <= arr[j])
        {
            temp[k++] = arr[i++];
        }
        else
        {
            temp[k++] = arr[j++];
            inversions += (mid - i + 1);
        }
    }

    while (i <= mid)
    {
        temp[k++] = arr[i++];
    }

    while (j <= right)
    {
        temp[k++] = arr[j++];
    }

    for (i = left; i <= right; i++)
    {
        arr[i] = temp[i];
    }

    return inversions;
}

long long mergeSortAndCount(long long arr[], int temp[], int left, int right)
{
    long long inversions = 0;
    if (left < right)
    {
        int mid = left + (right - left) / 2;

        inversions += mergeSortAndCount(arr, temp, left, mid);
        inversions += mergeSortAndCount(arr, temp, mid + 1, right);

        inversions += mergeAndCount(arr, temp, left, mid, right);
    }
    return inversions;
}

int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        int n, i;
        cin >> n;
        long long arr[n];
        int temp[n];
        for (i = 0; i < n; i++)
            cin >> arr[i];

        cout << mergeSortAndCount(arr, temp, 0, n - 1) << endl;
    }
    return 0;
}

/*int mergeAndCount(vector<int> &arr, vector<int> &temp, int left, int mid, int right)
{
    int i = left, j = mid + 1, k = left;
    int inversions = 0;

    while (i <= mid && j <= right)
    {
        if (arr[i] <= arr[j])
        {
            temp[k++] = arr[i++];
        }
        else
        {
            temp[k++] = arr[j++];
            inversions += (mid - i + 1);
        }
    }

    while (i <= mid)
    {
        temp[k++] = arr[i++];
    }

    while (j <= right)
    {
        temp[k++] = arr[j++];
    }

    for (i = left; i <= right; i++)
    {
        arr[i] = temp[i];
    }

    return inversions;
}

int mergeSortAndCount(vector<int> &arr, vector<int> &temp, int left, int right)
{
    int inversions = 0;
    if (left < right)
    {
        int mid = left + (right - left) / 2;

        inversions += mergeSortAndCount(arr, temp, left, mid);
        inversions += mergeSortAndCount(arr, temp, mid + 1, right);

        inversions += mergeAndCount(arr, temp, left, mid, right);
    }
    return inversions;
}*/
