#include <iostream>
#include <vector>
#include <algorithm> // For lower_bound
using namespace std;

class Solution
{
public:
    int searchInsert(vector<int> &nums, int target)
    {
        auto it = lower_bound(nums.begin(), nums.end(), target); // Find the position using lower_bound
        return it - nums.begin();                                // Return the index of the position
    }
};

int main()
{
    Solution sol;
    vector<int> nums = {1, 3, 5, 6};
    int target = 5;

    int result = sol.searchInsert(nums, target);
    cout << "The target should be inserted at index: " << result << endl;

    return 0;
}
