#include <iostream>
#include <cmath> // For sqrt() function

int countPerfectSquares(int n)
{
    return std::floor(std::sqrt(n));
}

int main()
{
    int n;
    std::cin >> n;

    int result = countPerfectSquares(n);
    std::cout << "Number of perfect squares between 1 and " << n << " is: " << result << std::endl;

    return 0;
}
