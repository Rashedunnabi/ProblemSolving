#include <bits/stdc++.h>
using namespace std;

long long expo(long long a, long long b, long long mod)
{
    long long res = 1;
    while (b > 0)
    {
        if (b & 1)
            res = (res * a) % mod;
        a = (a * a) % mod;
        b = b >> 1;
    }
    return res;
}
void extendgcd(long long a, long long b, long long *v)
{
    if (b == 0)
    {
        v[0] = 1;
        v[1] = 0;
        v[2] = a;
        return;
    }
    extendgcd(b, a % b, v);
    long long x = v[1];
    v[1] = v[0] - v[1] * (a / b);
    v[0] = x;
    return;
} // pass an arry of size1 3
long long mminv(long long a, long long b)
{
    long long arr[3];
    extendgcd(a, b, arr);
    return arr[0];
} // for non prime b
long long mminvprime(long long a, long long b) { return expo(a, b - 2, b); }
long long mod_add(long long a, long long b, long long m)
{
    a = a % m;
    b = b % m;
    return (((a + b) % m) + m) % m;
}
long long mod_mul(long long a, long long b, long long m)
{
    a = a % m;
    b = b % m;
    return (((a * b) % m) + m) % m;
}
long long mod_sub(long long a, long long b, long long m)
{
    a = a % m;
    b = b % m;
    return (((a - b) % m) + m) % m;
}
long long mod_div(long long a, long long b, long long m)
{
    a = a % m;
    b = b % m;
    return (mod_mul(a, mminvprime(b, m), m) + m) % m;
} // only for prime m

struct Hashing
{
    string s;
    int n;
    int primes;
    vector<long long> hashPrimes = {1000000009, 100000007};
    const long long base = 31;
    vector<vector<long long>> hashValues;
    vector<vector<long long>> powersOfBase;
    vector<vector<long long>> inversePowersOfBase;
    Hashing(string a)
    {
        primes = (int)hashPrimes.size();
        hashValues.resize(primes);
        powersOfBase.resize(primes);
        inversePowersOfBase.resize(primes);
        s = a;
        n = s.length();
        for (int i = 0; i < (int)hashPrimes.size(); i++)
        {
            powersOfBase[i].resize(n + 1);
            inversePowersOfBase[i].resize(n + 1);
            powersOfBase[i][0] = 1;
            for (int j = 1; j <= n; j++)
            {
                powersOfBase[i][j] = (base * powersOfBase[i][j - 1]) % hashPrimes[i];
            }
            inversePowersOfBase[i][n] = mminvprime(powersOfBase[i][n], hashPrimes[i]);
            for (int j = n - 1; j >= 0; j--)
            {
                inversePowersOfBase[i][j] = mod_mul(inversePowersOfBase[i][j + 1], base, hashPrimes[i]);
            }
        }
        for (int i = 0; i < (int)hashPrimes.size(); i++)
        {
            hashValues[i].resize(n);
            for (int j = 0; j < n; j++)
            {
                hashValues[i][j] = ((s[j] - 'a' + 1LL) * powersOfBase[i][j]) % hashPrimes[i];
                hashValues[i][j] = (hashValues[i][j] + (j > 0 ? hashValues[i][j - 1] : 0LL)) % hashPrimes[i];
            }
        }
    }
    vector<long long> substringHash(int l, int r) // O(1)
    {
        vector<long long> hash(primes);
        for (int i = 0; i < primes; i++)
        {
            long long val1 = hashValues[i][r];
            long long val2 = l > 0 ? hashValues[i][l - 1] : 0LL;
            hash[i] = mod_mul(mod_sub(val1, val2, hashPrimes[i]), inversePowersOfBase[i][l], hashPrimes[i]);
        }
        return hash;
    }
};

/*
  struct Hashing h = Hashing(str); // O(n)
  // call the Hashing
  vector<long long> hash = h.substringHash(l, r);
  //for segment l--r ,it gives a hash value in vector form

*/

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        long long n, k, kc;
        cin >> n >> k >> kc;
        string str;
        cin >> str;

        struct Hashing h = Hashing(str); // O(n)

        long long low = 1;
        long long high = n;
        long long ans = 0;
        while (low <= high)
        {
            long long mid = (low + high) >> 1;
            long long c = 1;
            long long l = 0;
            long long r = mid - 1;
            vector<long long> hash = h.substringHash(l, r);
            l = mid;
            r = l + mid - 1;
            while (r < n && l <= r)
            {
                if (h.substringHash(l, r) == hash)
                {
                    c++;
                    l = r + 1;
                    r = l + mid - 1;
                }
                else
                {
                    l++;
                    r++;
                }
            }
            if (c >= k)
            {
                ans = mid;
                low = mid + 1;
            }
            else
                high = mid - 1;
        }
        cout << ans << endl;
    }
    return 0;
}
