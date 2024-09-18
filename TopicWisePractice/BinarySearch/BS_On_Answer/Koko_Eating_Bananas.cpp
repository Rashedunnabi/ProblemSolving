#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    // Function to check if we can eat all bananas within h hours at speed mid
    bool check(vector<int> &piles, int h, int mid)
    {
        int cnt = 0;
        for (auto &pile : piles)
        {
            // Calculate the number of hours required for each pile
            cnt += (pile + mid - 1) / mid;
        }
        // Return true if the total hours needed is less than or equal to h
        return cnt <= h;
    }

    // Function to find the minimum eating speed
    int minEatingSpeed(vector<int> &piles, int h)
    {
        int lo = 1, hi = 1000000000;
        while (lo < hi)
        {
            int mid = lo + (hi - lo) / 2;
            if (check(piles, h, mid))
            {
                hi = mid; // Mid is a valid speed, try smaller speeds
            }
            else
            {
                lo = mid + 1; // Mid is not valid, increase speed
            }
        }
        // Return the minimum valid speed
        return lo;
    }
};

// Example usage
int main()
{
    Solution sol;
    vector<int> piles = {3, 6, 7, 11};
    int h = 8;
    cout << "Minimum eating speed is: " << sol.minEatingSpeed(piles, h) << endl;
    return 0;
}
