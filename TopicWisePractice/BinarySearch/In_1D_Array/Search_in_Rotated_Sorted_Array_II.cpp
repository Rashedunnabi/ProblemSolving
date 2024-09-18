#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    bool search(vector<int> &nums, int target)
    {
        int lo = 0, hi = nums.size() - 1, mid;
        while (lo <= hi)
        {
            mid = lo + (hi - lo) / 2;

            if (nums[mid] == target)
                return true;

            // Handle duplicates
            if (nums[lo] == nums[mid] && nums[hi] == nums[mid])
            {
                lo++;
                if (hi > 0)
                    hi--;
            }
            // Left half is sorted
            else if (nums[lo] <= nums[mid])
            {
                if (nums[lo] <= target && target <= nums[mid])
                    hi = mid - 1;
                else
                    lo = mid + 1;
            }
            // Right half is sorted
            else
            {
                if (nums[mid] < target && target <= nums[hi])
                    lo = mid + 1;
                else
                    hi = mid - 1;
            }
        }
        return false;
    }
};

int main()
{
    Solution sol;
    vector<int> nums = {2, 5, 6, 0, 0, 1, 2};
    int target = 0;

    bool result = sol.search(nums, target);
    if (result)
        cout << "Element found in the array." << endl;
    else
        cout << "Element not found in the array." << endl;

    return 0;
}
