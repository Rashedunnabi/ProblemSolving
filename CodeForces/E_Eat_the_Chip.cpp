#include <bits/stdc++.h>
using namespace std;

#define Faster ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
#define Alice cout << "Alice\n"
#define Bob cout << "Bob\n"
#define Draw cout << "Draw\n"
#define ll long long

int main()
{
    Faster;
    int t = 1;
    cin >> t;
    while (t--)
    {
        ll n, m, ax, ay, bx, by, dif = 0, mid = 0;
        cin >> n >> m >> ax >> ay >> bx >> by;

        if (ax >= bx)
        {
            Draw;
            continue;
        }
        dif = bx - ax;
        ll al, ar, bl, br;

        if (dif & 1) // alice chance
        {
            mid = dif >> 1;
            al = max(1LL, ay - mid - 1);
            ar = min(m, ay + mid + 1);

            bl = max(1LL, by - mid);
            br = min(m, by + mid);

            // check the llerval
            if (al <= bl && ar >= br)
                Alice;
            else
                Draw;
        }
        else // bob chance
        {
            mid = (dif >> 1);
            al = max(1LL, ay - mid);
            ar = min(m, ay + mid);

            bl = max(1LL, by - mid);
            br = min(m, by + mid);

            // check the llerval
            if (bl <= al && br >= ar)
                Bob;
            else
                Draw;
        }
    }
    return 0;
}