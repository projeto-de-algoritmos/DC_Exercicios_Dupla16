// 559B - Equivalent Strings
// https://codeforces.com/problemset/problem/559/B
#include <bits/stdc++.h>

using namespace std;
using ll = long long;

void sortPartitions_r(string &str)
{
    if (str.size() & 1)
        return;

    string str1 = str.substr(0, str.size() / 2);
    string str2 = str.substr(str.size() / 2, str.size() / 2);
    sortPartitions_r(str1);
    sortPartitions_r(str2);

    if (str1 > str2)
        str = str2 + str1;
    else
        str = str1 + str2;
}

string sortPartitions(string str)
{
    sortPartitions_r(str);
    return str;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string a, b;
    cin >> a >> b;

    string aSorted = sortPartitions(a);
    string bSorted = sortPartitions(b);

    cout << (aSorted == bSorted ? "YES" : "NO") << endl;

    return 0;
}
