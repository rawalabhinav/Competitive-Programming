#include <bits/stdc++.h>
using namespace std;

#ifdef RAWAL
    #include <Collections/debug.h>
#endif

#define int long long int

int n, m;
vector <vector <int>> adj;
vector <int> vis;

void dfs(int u, int team){
    if (vis[u] == team) return;
    else if (vis[u]){
        cout << "IMPOSSIBLE";
        exit(0);
    }

    vis[u] = team;
    team = !(team - 1) + 1;

    for(int& v: adj[u]){
        dfs(v, team);
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
        if (!vis[i]) dfs(i, 1);
        cout << vis[i] << ' ';
    }
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
}