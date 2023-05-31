#include <bits/stdc++.h>
using namespace std;

#ifdef RAWAL
    #include <Collections/debug.h>
#endif

#define int long long int

int n, m;
vector <vector <int>> adj;
vector <int> vis, node;

void dfs(int u){
    if (vis[u]) return;

    vis[u] = true;
    for(int& v: adj[u]) dfs(v);
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
        if (!vis[i]){
            node.emplace_back(i);
            dfs(i);
        }
    }

    cout << (int) node.size() - 1 << '\n';
    for(int i = 1; i < node.size(); ++i){
        cout << node[0] << ' ' << node[i] << '\n';
    }
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
}