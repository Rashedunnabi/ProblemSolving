#include <bits/stdc++.h>
using namespace std;

// Function to reverse the digits of a number
int reverseDigits(int num)
{
    int reversedNum = 0;
    while (num > 0)
    {
        reversedNum = reversedNum * 10 + num % 10;
        num /= 10;
    }
    return reversedNum;
}

// Function to determine the winner of the game
string determineWinner(int n, int m, vector<int> &nums)
{
    if (m == 0)
        return "Sasha"; // Sasha wins if m is 0

    for (int num : nums)
    {
        if (num >= pow(10, m))
            return "Sasha"; // Sasha wins if there's a number >= 10^m
        if (reverseDigits(num) >= pow(10, m))
            return "Anna"; // Anna wins if there's a number whose reverse is >= 10^m
    }

    // If neither Sasha nor Anna can win with their optimal moves, it's a draw
    return "Draw";
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, m;
        cin >> n >> m;
        vector<int> nums(n);
        for (int i = 0; i < n; ++i)
        {
            cin >> nums[i];
        }
        cout << determineWinner(n, m, nums) << endl;
    }
    return 0;
}
