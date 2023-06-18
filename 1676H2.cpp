// 1676H2 - Maximum Crossings (Hard Version)
// https://codeforces.com/problemset/problem/1676/H2
#include <bits/stdc++.h>

using namespace std;
using ll = long long;

ll count_inversions(vector<int>::iterator left, vector<int>::iterator right)
{
    if (left + 1 == right)
        return 0;

    auto middle = left + distance(left, right) / 2;
    ll inversions_left = count_inversions(left, middle);
    ll inversions_right = count_inversions(middle, right);

    ll inversions_merge = 0;
    vector<int> aux(distance(left, right));
    vector<int>::iterator pl = left, pr = middle, paux = aux.begin();

    while (pl < middle && pr < right)
    {
        if (*pl >= *pr)
        {
            inversions_merge += distance(pl, middle);
            *paux = *pr;
            pr++;
        }
        else
        {
            *paux = *pl;
            pl++;
        }
        paux++;
    }

    if (pl == middle)
        while (pr < right)
            *(paux++) = *(pr++);
    if (pr == right)
        while (pl < middle)
            *(paux++) = *(pl++);

    for (auto p = aux.begin(), q = left; p < aux.end(); p++, q++)
        *q = *p;

    return inversions_left + inversions_right + inversions_merge;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t, n;
    cin >> t;
    while (t--)
    {
        cin >> n;
        vector<int> wires(n);
        for (int i = 0; i < n; i++)
            cin >> wires[i];
        cout << count_inversions(wires.begin(), wires.end()) << endl;
    }
    
    return 0;
}
