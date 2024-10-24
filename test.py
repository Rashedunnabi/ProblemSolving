import sys
from math import gcd

def calculate_compositeness(N, A):
    compositeness = [0] * N

    # Iterate through each index as the center
    for i in range(N):
        current_gcd = A[i]
        left = i
        right = i

        # Expand to the left
        while left >= 0 and current_gcd > 1:
            compositeness[i] = max(compositeness[i], right - left + 1)
            left -= 1
            if left >= 0:
                current_gcd = gcd(current_gcd, A[left])

        # Reset current_gcd and expand to the right
        current_gcd = A[i]
        left = i
        right = i

        while right < N and current_gcd > 1:
            compositeness[i] = max(compositeness[i], right - left + 1)
            right += 1
            if right < N:
                current_gcd = gcd(current_gcd, A[right])

    return compositeness

# Input reading
N = int(input().strip())
A = list(map(int, input().strip().split()))

# Calculate compositeness
result = calculate_compositeness(N, A)

# Output the result
print(' '.join(map(str, result)))
