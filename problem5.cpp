/*Easy Enough? (Public Contest: CodeRush October'23)

You are given a binary string of length N, where each character is either '0' or '1'. Additionally, you have two types of queries that are being performed on this binary string:
1 l r: Flip all the bits in the binary string from index l to index r (inclusive). Flipping a bit means changing '0' to '1' and '1' to '0'.
2 l r: This query asks you to find the goodness of the substring from index l to index r (inclusive).

The goodness of a binary string is defined as the sum of the squares of indices where '1' occurs in the binary string. In other words, for each '1' in the binary string at index i, the contribution to the goodness is i2 .  
Assume 1 based indexing in the Question.
Input
Input:
The first line contains an integer N, representing the length of the binary string.
The second line contains a binary string of length N.
The third line contains an integer Q, representing the number of queries.
The next Q lines contain 3 integers each, each representing a query, format of which is discussed above.

Constraints

1<=N, Q<=100000
There is at least one query of type 2.
Output
Output:
For each query of type 2, output a single integer, the goodness of that query.
Example
Input:
10
1001100111
5
2 1 10
1 2 5
2 1 5
2 5 6
2 7 9

Output:
287
14
0
13*/
/*---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------*/


#include<bits/stdc++.h>
using namespace std;

typedef long long   ll;
#define endl        "\n"

struct node {
    vector<vector<ll>> dp;

    // dp   ->   0,   1,      2
    // ones -> cnt, sum, square
    // zero -> cnt, sum, square

    node() {
        dp.resize(2, vector<ll>(3, 0));
    }
};

class LazySegTree {
public:
    ll n;
    vector<node> seg;
    vector<int> lazy;

    LazySegTree(string &s) {
        this->n = (ll) s.size();
        seg.resize(4 * n + 4, node());
        lazy.resize(4 * n + 4);
        build(0, 0, n - 1, s);
    }

    node merge(node left, node right) {
        node ret = node();

        for (int i = 0; i < 2; i++) {
            for (int j = 0; j < 3; j++)
                ret.dp[i][j] = left.dp[i][j] + right.dp[i][j];
        }

        return ret;
    }

    void build(ll ind, ll low, ll high, string &s) {
        if (low == high) {
            ll val = (low + 1);
            int v = s[low] - '0';

            seg[ind].dp[v][0] = 1;
            seg[ind].dp[v][1] = val;
            seg[ind].dp[v][2] = (val * val);

            return;
        }

        ll mid = low + (high - low) / 2;
        build(2 * ind + 1, low, mid, s);
        build(2 * ind + 2, mid + 1, high, s);
        seg[ind] = merge(seg[2 * ind + 1], seg[2 * ind + 2]);
    }

    void propogate(ll ind, ll low, ll high) {
        if (lazy[ind] == 0) return;

        swap(seg[ind].dp[0], seg[ind].dp[1]);

        if (low != high) {
            lazy[2 * ind + 1] ^= lazy[ind];
            lazy[2 * ind + 2] ^= lazy[ind];
        }

        lazy[ind] = 0;
    }

    void update(ll ind, ll low, ll high, ll l, ll r) {
        propogate(ind, low, high);

        if (r < low || high < l) return;

        if (l <= low && high <= r) {
            lazy[ind] ^= 1;
            propogate(ind, low, high);
            return;
        }

        ll mid = low + (high - low) / 2;
        update(2 * ind + 1, low, mid, l, r);
        update(2 * ind + 2, mid + 1, high, l, r);
        seg[ind] = merge(seg[2 * ind + 1], seg[2 * ind + 2]);
    }

    node query(ll ind, ll low, ll high, ll l, ll r) {
        propogate(ind, low, high);

        if (high < l || r < low) return node();

        if (l <= low && high <= r) {
            propogate(ind, low, high);
            return seg[ind];
        }

        ll mid = low + (high - low) / 2;
        node left = query(2 * ind + 1, low, mid, l, r);
        node right = query(2 * ind + 2, mid + 1, high, l, r);
        return merge(left, right);
    }

    void Update(ll l, ll r) {
        update(0, 0, n - 1, l - 1, r - 1);
    }

    ll Query(ll l, ll r) {
        node ans = query(0, 0, n - 1, l - 1, r - 1);

        ll a = l - 1;
        ll cntOnes = ans.dp[1][0];
        ll sumOfOnes = ans.dp[1][1];
        ll squareSumOfOnes = ans.dp[1][2];

        ll mul = sumOfOnes - (cntOnes * a);
        mul *= a;
        mul *= 2;

        ll sub = mul;
        sub += (cntOnes * a * a);

        ll res = squareSumOfOnes - sub;
        return res;
    }
};

void solve() {
    ll n;
    cin >> n;

    string s;
    cin >> s;

    LazySegTree LSGTree(s);

    ll q, t, l, r;
    cin >> q;

    for (int i = 0; i < q; i++) {
        cin >> t >> l >> r;

        if (t == 1) {
            LSGTree.Update(l, r);
        }

        else {
            ll ans = LSGTree.Query(l, r);
            cout << ans << endl;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cout.tie(NULL); cin.tie(NULL);
    ll t = 1;
    // cin >> t;
    while (t--) solve();
    return 0;
}