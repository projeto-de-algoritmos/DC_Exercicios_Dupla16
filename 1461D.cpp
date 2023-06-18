// 1461D - Divide and Summarize
// https://codeforces.com/problemset/problem/1461/D

#include <bits/stdc++.h>

using namespace std;
using ll = long long;

void possibleSums_r(vector<ll>::iterator left, vector<ll>::iterator right, set<ll> &sums)
{
    sums.insert(accumulate(left, right, 0LL));

    ll m = (*left + *(right - 1)) / 2;

    if (m >= *(right - 1))
        return;

    auto mp = upper_bound(left, right, m);
    possibleSums_r(left, mp, sums);
    possibleSums_r(mp, right, sums);
}

set<ll> possibleSums(vector<ll> &v)
{
    set<ll> sums;
    possibleSums_r(v.begin(), v.end(), sums);
    return sums;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll t, n, q;
    cin >> t;
    while (t--)
    {
        cin >> n >> q;
        vector<ll> as(n);
        for (int i = 0; i < n; i++)
            cin >> as[i];

        sort(as.begin(), as.end());
        set<ll> sums = possibleSums(as);
        ll sumQuery;
        while (q--)
        {
            cin >> sumQuery;
            cout << (sums.find(sumQuery) != sums.end() ? "Yes" : "No") << endl;
        }
    }
    
    return 0;
}