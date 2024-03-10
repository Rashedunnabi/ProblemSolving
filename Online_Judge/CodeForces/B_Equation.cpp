#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
    double a, b, c, x1 = 0, x2 = 0;
    cin >> a >> b >> c;

    double determine = (b * b) - (4 * a * c);

    if (!a and !b and !c)
        cout << -1 << '\n';
    else if (determine < 0 or (!a and !b) or (!b and !c) or (!a and !c))
        cout << "0\n";
    else if (a == 0)
        printf("1\n%.6lf\n", -c / b);
    else if (determine == 0)
        printf("1\n%.6lf\n", -b / (2.0 * a));
    else
    {
        x1 = (-b + sqrt(determine)) / (2.0 * a);
        x2 = (-b - sqrt(determine)) / (2.0 * a);
        if (x1 > x2)
            swap(x1, x2);
        printf("2\n%.10lf %.10lf\n", x1, x2);
    }
    return 0;
}