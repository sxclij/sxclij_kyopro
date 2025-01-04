
#include <bits/stdc++.h>
using namespace std;
typedef int64_t ll;
typedef pair<ll, ll> pi;

#define rep(i, n) for (ll i = 0; i < n; i++)

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    ll h, w;
    cin >> h >> w;

    vector<pi> task;
    ll start_muki;

    char t1;
    char s[1002][1002] = {'#'};
    ll cost[1002][1002] = {1000000};
    rep(i, h) rep(j, w) {
        cin >> t1;
        s[i + 1][j + 1] = t1;
        if (t1 == 'S') {
            task.push_back(make_pair(i + 1, j + 1));
            start_muki = i + 1 + j + 1 % 2;
        }
    }
    while (task.size() != 0) {
        pi current_src = task.back();
        task.pop_back();
        if (s[current_src.first][current_src.second] == 'G') {
            cout << cost[current_src.first][current_src.second] << end;
            ;
            return 0;
        }
        ll current_score = cost[current_src.first][current_src.second] + 1;
        pi current_dst1;
        pi current_dst2;
        if (current_src.first + current_src.second % 2 == start_muki) {
            current_dst1 = make_pair(current_src.first, current_src.second + 1);
            current_dst2 = make_pair(current_src.first, current_src.second - 1);
        } else {
            current_dst1 = make_pair(current_src.first + 1, current_src.second);
            current_dst2 = make_pair(current_src.first - 1, current_src.second);
        }
        ll current_best1 = cost[current_dst1.first][current_dst1.second];
        ll current_best2 = cost[current_dst2.first][current_dst2.second];
        if (current_score > current_best1 && s[current_dst1.first][current_dst1.second] != '#') {
            task.push_back(current_dst1);
            cost[current_dst1.first][current_dst1.second] = current_score;
        }
        if (current_score > current_best2 && s[current_dst2.first][current_dst2.second] != '#') {
            task.push_back(current_dst2);
            cost[current_dst2.first][current_dst2.second] = current_score;
        }
    }
    cout << (ll)(-1) << endl;
}