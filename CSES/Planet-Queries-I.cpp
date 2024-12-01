#include <bits/stdc++.h>
using namespace std;

#ifdef RAWAL
#include <Collections/debug.h>
#endif

#define int long long int

void solve() {
    int n, queries, k = 30;
    cin >> n >> queries;

    vector <vector <int>> ancestor(n + 1, vector <int>(k, -1));

    for (int v, u = 1; u <= n; ++u) {
        cin >> v;
        ancestor[u][0] = v;
    }

    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j < k; ++j) {
            ancestor[i][j] = ancestor[i][j - 1] == -1
                ? -1
                : ancestor[ancestor[i][j - 1]][j - 1];
        }
    }

    for (int planet, jumps, res; queries > 0; --queries) {
        cin >> planet >> jumps;

        res = planet;

        for (int i = 0, j = 1; i < k; ++i, j <<= 1) {
            if (jumps & j) res = ancestor[res][i];
        }

        cout << res << '\n';
    }

}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
}
