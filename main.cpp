
#include <bits/stdc++.h>
using namespace std;
typedef int64_t ll;
typedef pair<ll, ll> pi;

#define rep(i, n) for (ll i = 0; i < n; i++)

ll f1(ll src) {
    string str = to_string(src);
    ll sentou = str[0] - '0';
    ll keta = str.size();
    ll dst = 1;
    for (ll i = 1; i <= keta; i++) {
        dst *= sentou - (str[i] - '0');
    }
    return dst;
}

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    ll l, r;
    cin >> l >> r;
    ll l_ans = f1(l);
    ll r_ans = f1(r);
    cout << r_ans - l_ans << endl;
}