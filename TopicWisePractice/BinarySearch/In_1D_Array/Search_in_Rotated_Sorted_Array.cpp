#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    int search(vector<int> &nums, int target)
    {
        int lo = 0, hi = nums.size() - 1, mid;

        while (lo <= hi)
        {
            mid = lo + (hi - lo) / 2;

            if (nums[mid] == target)
                return mid;

            // Check if left half is sorted
            if (nums[lo] <= nums[mid])
            {
                if (nums[lo] <= target && target < nums[mid])
                    hi = mid - 1; // Target in left half
                else
                    lo = mid + 1; // Target in right half
            }
            // Right half is sorted
            else
            {
                if (nums[mid] < target && target <= nums[hi])
                    lo = mid + 1; // Target in right half
                else
                    hi = mid - 1; // Target in left half
            }
        }

        return -1; // Target not found
    }
};

int main()
{
    ios_base::sync_with_stdio(0); // Fast I/O
    Solution sol;
    vector<int> nums = {4, 5, 6, 7, 0, 1, 2}; // Rotated sorted array
    int target = 0;

    int result = sol.search(nums, target);
    if (result != -1)
        cout << "Element found at index: " << result << endl;
    else
        cout << "Element not found in the array." << endl;

    return 0;
}
