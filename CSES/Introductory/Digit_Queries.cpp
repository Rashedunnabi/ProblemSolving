#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main()
{
    vector<ll> power(18, 0);
    for (ll i = 1; i < 18; i++)
    {
        power[i] = (pow(10, i) - pow(10, i - 1)) * i;
    }

    ll t, k;
    cin >> t;
    while (t--)
    {
        cin >> k;

        ll sum = 0;
        ll length_of_number = 0;
        for (ll i = 0; i <= 17; i++)
        {
            sum += power[i];
            if (sum <= k)
            {
                length_of_number = i + 1;
            }
            else
            {
                break;
            }
        }

        sum -= power[length_of_number];

        ll difference = k - sum;

        ll starting_number = pow(10, length_of_number - 1);
        ll distance_from_starting_number = (difference / length_of_number);
        ll actual_number = starting_number + distance_from_starting_number - 1;
        ll remainder = difference % length_of_number;

        if (remainder == 0)
        {
            cout << actual_number % 10 << endl;
        }
        else
        {
            actual_number++;
            remainder = length_of_number - remainder;
            while (remainder--)
            {
                actual_number /= 10;
            }
            cout << actual_number % 10 << endl;
        }
    }
    return 0;
}