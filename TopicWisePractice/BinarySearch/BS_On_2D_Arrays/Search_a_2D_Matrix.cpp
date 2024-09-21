#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    bool searchMatrix(vector<vector<int>> &matrix, int k)
    {
        int rows = matrix.size();
        if (rows == 0)
            return false; // Handle edge case for empty matrix

        int cols = matrix[0].size();
        int lo = 0, hi = cols - 1;

        while (lo < rows && hi >= 0)
        {
            int x = matrix[lo][hi];

            if (x == k)
                return true;
            if (x < k)
                lo++; // Move down if the current element is smaller than k
            else
                hi--; // Move left if the current element is greater than k
        }
        return false; // Element not found
    }
};

int main()
{
    vector<vector<int>> matrix = {
        {1, 4, 7, 11},
        {2, 5, 8, 12},
        {3, 6, 9, 16},
        {10, 13, 14, 17}};
    int k;
    cout << "Enter the element to search: ";
    cin >> k;

    Solution obj;
    bool result = obj.searchMatrix(matrix, k);

    if (result)
        cout << "Element found in the matrix." << endl;
    else
        cout << "Element not found in the matrix." << endl;

    return 0;
}
