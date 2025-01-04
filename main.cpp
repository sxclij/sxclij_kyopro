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

    queue<pi> task;
    ll start_muki;

    static char s[1002][1002];
    static ll cost[1002][1002];
    static bool visited[1002][1002];
    ll ans = 1000000;

    rep(i, h + 2) rep(j, w + 2) {
        s[i][j] = '#';
        cost[i][j] = 1000000;
        visited[i][j] = false;
    }

    ll start_x = -1, start_y = -1;
    rep(i, h) rep(j, w) {
        cin >> s[i + 1][j + 1];
        if (s[i + 1][j + 1] == 'S') {
            start_x = i + 1;
            start_y = j + 1;
            start_muki = (i + 1 + j + 1) % 2;
        }
    }

    if (start_x != -1) {
        task.push({start_x, start_y});
        cost[start_x][start_y] = 0;
        visited[start_x][start_y] = true;
    }

    while (!task.empty()) {
        pi current_src = task.front();
        task.pop();

        if (s[current_src.first][current_src.second] == 'G') {
            ans = min(ans, cost[current_src.first][current_src.second]);
            continue;
        }

        ll current_score = cost[current_src.first][current_src.second] + 1;
        pi current_dst1, current_dst2;

        if ((current_src.first + current_src.second) % 2 != start_muki) {
            current_dst1 = {current_src.first, current_src.second + 1};
            current_dst2 = {current_src.first, current_src.second - 1};
        } else {
            current_dst1 = {current_src.first + 1, current_src.second};
            current_dst2 = {current_src.first - 1, current_src.second};
        }

        auto check_and_enqueue = [&](pi dst) {
            if (s[dst.first][dst.second] != '#' && !visited[dst.first][dst.second]) {
                cost[dst.first][dst.second] = current_score;
                visited[dst.first][dst.second] = true;
                task.push(dst);
            }
        };

        check_and_enqueue(current_dst1);
        check_and_enqueue(current_dst2);
    }

    if (ans == 1000000) {
        cout << -1 << endl;
    } else {
        cout << ans << endl;
    }

    return 0;
}