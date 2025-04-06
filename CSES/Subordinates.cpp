#include <bits/stdc++.h>
using namespace std;

#ifdef RAWAL
    #include <Collections/debug.h>
#endif

void solve(){
    int n; cin >> n;

    vector <vector <int>> adj(n + 1);
    vector <int> ans(n + 1);
    for (int boss, i = 2; i <= n; ++i) {
        cin >> boss;

        adj[boss].emplace_back(i);
    }

    function <int(int)> dfs = [&](int u) {
        int subordinates = 0;
        for (int& v: adj[u]) subordinates += dfs(v);
        ans[u] = subordinates;

        return 1 + subordinates;
    };


    dfs(1);
    for (int i = 1; i <= n; ++i) cout << ans[i] << ' ';
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
}