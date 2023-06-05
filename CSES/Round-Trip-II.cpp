#include <bits/stdc++.h>
using namespace std;

#ifdef RAWAL
    #include <Collections/debug.h>
#endif

#define int long long int

vector <vector <int>> adj;
vector <int> vis, d, ans;

void dfs(int u, int p){
    if (!vis[u]){
        vis[u] = 1, d[u] = p;
        for(int& v: adj[u]) dfs(v, u);
        d[u] = 0; return;
    }

    if (!d[u]) return;

    for(ans.emplace_back(u); p != u; p = d[p]){
        ans.emplace_back(p);
    }

    reverse(ans.begin(), ans.end());
    cout << ans.size() + 1 << '\n' << u  << ' ';
    
    for(int& e: ans) cout << e << ' ';
    exit(0);
}

void solve(){
    int n, m; cin >> n >> m;

    adj.resize(n + 1), vis.resize(n + 1);
    d.resize(n + 1);

    for(int u, v, i = 0; i < m; ++i){
        cin >> u >> v;

        adj[u].emplace_back(v);
    }

    for(int i = 1; i <= n; ++i){
        if (!vis[i]) dfs(i, i);
    } cout << "IMPOSSIBLE";
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
}