#include <bits/stdc++.h>
using namespace std;

#ifdef RAWAL
    #include <Collections/debug.h>
#endif

#define int long long int

int n, m;
vector <vector <int>> adj;
vector <int> vis, node;

void dfs(int u, int p){
    if (vis[u]) {
        for(; p != u; p = vis[p]){
            node.emplace_back(p);
        }

        cout << node.size() + 2 << '\n' << u << ' ';
        for(int& e: node) cout << e << ' ';
        cout << u; exit(0);
    }

    vis[u] = p;
    for(int& v: adj[u]){
        if (v != vis[u]) dfs(v, u);
    }
}

void solve(){
    cin >> n >> m;

    adj.resize(n + 1), vis.resize(n + 1);
    for(int u, v, i = 0; i < m; ++i){
        cin >> u >> v;

        adj[u].emplace_back(v);
        adj[v].emplace_back(u);
    }

    for(int i = 1; i <= n; ++i){
        if (!vis[i]) dfs(i, i);
    }

    cout << "IMPOSSIBLE";
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
}