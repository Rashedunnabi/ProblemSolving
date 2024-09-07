#include <bits/stdc++.h>
using namespace std;
class Solution
{
private:
    bool check(int n, int k, int mid, vector<int> &ar)
    {
        int remainCow = k - 1, pre = ar[0];
        for (int i = 1; i < n; i++)
        {
            if (ar[i] - pre >= mid)
            {
                pre = ar[i];
                remainCow--;
            }
            if (remainCow == 0)
                break;
        }
        return remainCow == 0;
    }

public:
    int solve(int n, int k, vector<int> &ar)
    {
        sort(ar.begin(), ar.end());
        int lo = 0, hi = ar[n - 1] + 10;
        while (hi - lo > 1)
        {
            int mid = lo + (hi - lo) / 2;
            if (check(n, k, mid, ar))
                lo = mid;
            else
                hi = mid;
        }
        return lo;
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
    cout << ob.solve(n, k, arr);
    return 0;
}