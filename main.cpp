
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

    ll h, w;
    cin >> h >> w;

    vector<pi> task;

    char t1;
    char s[1002][1002] = {'#'};
    ll best[1002][1002] = {1000000};
    rep(i, h) rep(j, w) {
        cin >> t1;
        s[i + 1][j + 1] = t1;
        if (t1 == 'S') {
            task.push_back(make_pair(i + 1, j + 1));
        }
    }
    while (task.size() != 0) {
        pi current_src = task.back();
        task.pop_back();
        pi current_dst1 = make_pair(current_src.first + 1, current_src.second);
        pi current_dst2 = make_pair(current_src.first - 1, current_src.second);
        ll current_best1 = best[current_dst1.first][current_dst1.second];
        ll current_score = best[current_src.first][current_src.second] + 1;
        if ()
    }
}