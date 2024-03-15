#include <bits/stdc++.h>
using namespace std;

#define Faster ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
#define bob cout << "Bob\n"
#define alice cout << "Alice\n"

int main()
{
    Faster;
    int t = 1;
    cin >> t;
    while (t--)
    {
        int n, a, b;
        cin >> n >> a >> b;
        if (a == b)
        {
            if (n > a)
            {
                if ((n - (a + 1)) % (a + 1) == 0)
                    bob;
                else
                    alice;
            }
            else
                alice;
        }
        else if (a < b)
        {
            if (n <= a)
                alice;
            else
                bob;
        }
        else
            alice;
    }
    return 0;
}