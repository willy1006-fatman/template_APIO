#pragma GCC optimize("O3,inline")
#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int N, M, K, a; cin >> N >> M >> K;
    vector<vector<int>> A(N, vector<int>(M, 0));
    vector<pair<int, int>> sums(N + 2, { 0, 0 });
    sums.back() = { M * K, 0 };
    sums[0].second = INT_MIN;
    for (int i = 0; i < N; i++) {
        sums[i + 1].second = -i;
        for (int j = 0; j < M; j++) {
            cin >> a;
            A[i][j] = a;
            sums[i + 1].first += a;
        }
    }
    sort(sums.begin(), sums.end());
    vector<vector<int>> dp(N + 1, vector<int>(M + 1, INT_MAX));
    dp[0][0] = 0;
    for (int i = 0; i < N; i++) {
        vector<bitset<10001>> dp1((sums[i + 2].first - sums[i].first) / K + 1, 0);
        dp1[0] = 1;
        for (int j = 0; j < M; j++) for (int k = (sums[i + 2].first - sums[i].first) / K; k > 0; k--) dp1[k] |= (dp1[k - 1] << A[-sums[i + 1].second][j]);
        for (int j = 0; j <= (sums[i + 2].first - sums[i].first) / K; j++) {
            queue<int> nums;
            for (int k = 10000; k >= 0; k--) if (dp1[j][k]) nums.push(k);
            for (int k = 0; j + k <= M; k++) {
                while (nums.size() && (nums.front() > sums[i + 1].first - dp[i][k] || (sums[i + 1].second < sums[i].second && nums.front() == sums[i + 1].first - dp[i][k]))) nums.pop();
                if (nums.empty()) break;
                dp[i + 1][j + k] = min(dp[i + 1][j + k], sums[i + 1].first - nums.front() + j * K);
            }
        }
    }
    for (int i = M; i >= 0; i--) {
        if (dp[N][i] != INT_MAX) {
            cout << N * M - i << '\n';
            return 0;
        }
    }
}