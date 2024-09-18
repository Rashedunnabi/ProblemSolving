#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
public:
    // Function to check if it's possible to make at least m bouquets with k flowers each by day `mid`
    bool check(vector<int> &ar, int m, int k, int mid)
    {
        int cnt = 0, ans = 0;
        for (int i = 0; i < ar.size(); i++)
        {
            if (ar[i] <= mid)
            {
                cnt++;
                if (cnt >= k)
                {
                    cnt -= k;
                    ans++;
                }
            }
            else
            {
                cnt = 0;
            }
        }
        return ans >= m;
    }

    // Function to find the minimum number of days required
    int minDays(vector<int> &bloomDay, int m, int k)
    {
        int n = bloomDay.size();
        if (1LL * n < 1LL * m * k)
            return -1; // Not enough flowers

        int lo = 0, hi = *max_element(bloomDay.begin(), bloomDay.end()) + 1;
        while (lo < hi)
        {
            int mid = lo + (hi - lo) / 2;
            if (check(bloomDay, m, k, mid))
                hi = mid;
            else
                lo = mid + 1;
        }
        return lo;
    }
};

// Example usage
int main()
{
    Solution sol;
    vector<int> bloomDay = {1, 10, 3, 10, 2};
    int m = 3;
    int k = 1;
    cout << "Minimum number of days required: " << sol.minDays(bloomDay, m, k) << endl;
    return 0;
}
