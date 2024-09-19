#include <bits/stdc++.h>
using namespace std;

int missingK(vector<int> vec, int n, int k)
{
    // If the first element is greater than k, the k-th missing number is simply k
    if (vec[0] > k)
        return k;
    // Binary search to find the position where the k-th missing number is located
    int lo = 0, hi = n;
    while (hi - lo > 1)
    {
        int mid = lo + (hi - lo) / 2;
        int missing = vec[mid] - (mid + 1); // Missing numbers until mid index
        if (missing < k)
            lo = mid;
        else
            hi = mid;
    }
    // Calculate how many missing numbers we still need after `lo`
    int miss = vec[lo] - (lo + 1);
    int more = k - miss;
    // Return the k-th missing number
    return vec[lo] + more;
    // or return lo+k+1;
}

int main()
{
    int n, k;
    cin >> n >> k;
    vector<int> v(n);
    for (int &i : v)
        cin >> i;
    cout << missingK(v, n, k) << '\n';
    return 0;
}
