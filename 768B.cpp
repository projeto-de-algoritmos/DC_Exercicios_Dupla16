// 768B - Code For 1
// https://codeforces.com/problemset/problem/768/B
#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int msb(ll x)
{
    int bit = 0;
    while (x > 0)
    {
        x >>= 1;
        bit++;
    }
    return bit;
}

ll getElement(ll n, ll pos, ll size)
{
    ll middle = size / 2;
    if (middle == pos)
        return n % 2;

    if (middle > pos)
        return getElement(n / 2, pos, middle);

    return getElement(n / 2, pos - middle - 1, middle);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll n, l, r;
    cin >> n >> l >> r;

    ll size = (1LL << msb(n)) - 1;
    
    ll count = 0;
    for (ll i = l - 1; i < r; i++)
        count += getElement(n, i, size);

    cout << count << endl;

    return 0;
}