#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // Function to check if a given capacity can ship all packages within 'days'
    bool check(vector<int> &ar, int days, int mid)
    {
        int cnt = 0, sum = 0;
        for (int i = 0; i < ar.size(); i++)
        {
            if (ar[i] > mid)
                return false; // If any package exceeds the current capacity, it's not feasible
            if (sum + ar[i] <= mid)
                sum += ar[i]; // Add package to the current shipment
            else
            {
                cnt++; // Start a new shipment
                sum = ar[i];
            }
        }
        if (sum)
            cnt++;          // Count the last shipment if there's any remaining
        return cnt <= days; // Return if the number of shipments is within the allowed days
    }

    // Function to find the minimum capacity required to ship all packages within 'days'
    int shipWithinDays(vector<int> &ar, int days)
    {
        int lo = *max_element(ar.begin(), ar.end());       // Minimum capacity should be at least the largest package
        int hi = accumulate(ar.begin(), ar.end(), 0) + 10; // Maximum capacity should be the sum of all packages plus a buffer

        while (hi - lo > 1)
        {
            int mid = lo + (hi - lo) / 2;
            if (check(ar, days, mid))
                hi = mid; // If feasible with current mid, try for a smaller capacity
            else
                lo = mid; // Otherwise, increase the capacity
        }
        return hi; // Return the minimum feasible capacity
    }
};

int main()
{
    int n, k;
    cin >> n >> k; // Read the number of packages and the number of days
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i]; // Read the package weights into the vector

    Solution ob;
    cout << ob.shipWithinDays(arr, k) << '\n'; // Output the minimum capacity required

    return 0;
}
