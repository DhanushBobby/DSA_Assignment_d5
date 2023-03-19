#include <bits/stdc++.h>
using namespace std;
bool isScramble(string S1, string S2)
{
    if (S1 == S2)
        return true;

    if (S1.length() != S2.length())
        return false;

    int n = S1.length();

    for (int i = 1; i < n; i++)
    {
        if (isScramble(S1.substr(0, i), S2.substr(0, i)) &&
            isScramble(S1.substr(i, n - i), S2.substr(i, n - i)))
            return true;

        if (isScramble(S1.substr(0, i), S2.substr(n - i, i)) &&
            isScramble(S1.substr(i, n - i), S2.substr(0, n - i)))
            return true;
    }
    return false;
}
int main()
{
    string s = "coder";
    string t = "ocder";
    cout << boolalpha << isScramble(s,t) << endl;
}