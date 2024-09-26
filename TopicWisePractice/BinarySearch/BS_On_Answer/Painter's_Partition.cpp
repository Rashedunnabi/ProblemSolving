#include <bits/stdc++.h>
using namespace std;

bool check(vector<int> &arr, int mid, int m)
{
    int cnt = 0, sum = 0, n = arr.size();
    for (int i = 0; i < n; i++)
    {
        if (sum + arr[i] > mid)
        {
            cnt++;
            sum = arr[i];
        }
        else
            sum += arr[i];
    }
    if (sum)
        cnt++;
    return cnt <= m;
}

int findLargestMinDistance(vector<int> &arr, int m)
{
    int lo = *max_element(arr.begin(), arr.end()) - 1,
        hi = accumulate(arr.begin(), arr.end(), 0) + 10;
    while (hi - lo > 1)
    {
        int mid = lo + (hi - lo) / 2;
        if (check(arr, mid, m))
            hi = mid;
        else
            lo = mid;
    }
    return hi;
}

int main()
{

    int n, m;
    cin >> n >> m;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    cout << findLargestMinDistance(arr, m) << '\n';
    return 0;
}