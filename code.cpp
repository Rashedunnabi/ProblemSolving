#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    bool check(vector<int> &ar, int days, int mid)
    {
        int cnt = 0, sum = 0;
        for (int i = 0; i < ar.size(); i++)
        {
            if (ar[i] > mid)
                return false;
            if (sum + ar[i] <= mid)
                sum += ar[i];
            else
            {
                cnt++;
                sum = ar[i];
            }
        }
        if (sum)
            cnt++;
        return cnt <= days;
    }
    int shipWithinDays(vector<int> &ar, int days)
    {
        int lo = 0, hi = accumulate(ar.begin(), ar.end(), 0) + 10;
        while (hi - lo > 1)
        {
            int mid = lo + (hi - lo) / 2;
            if (check(ar, days, mid))
                hi = mid;
            else
                lo = mid;
        }
        return hi;
    }
};

int main()
{

    int n, k;
    cin >> n >> k;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    Solution ob;
    cout << ob.shipWithinDays(arr, k) << '\n';

    return 0;
}