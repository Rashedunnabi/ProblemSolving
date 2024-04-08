#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
    int t = 1;
    cin >> t;
    while (t--)
    {
        string s;
        cin >> s;
        string flag = "AM";
        int hour = stoi(s.substr(0, 2));
        int minute = stoi(s.substr(3, 2));
        if (hour >= 12)
            flag = "PM";
        hour %= 12;
        if (hour == 0)
            hour = 12;
        cout << setw(2) << setfill('0') << hour << ':' << setw(2) << setfill('0') << minute << ' ' << flag << '\n';
    }
    return 0;
}