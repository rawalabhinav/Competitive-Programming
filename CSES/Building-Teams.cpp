#include <bits/stdc++.h>
using namespace std;

#ifdef RAWAL
    #include <Collections/debug.h>
#endif

void solve(){
    int n, m; cin >> n >> m;
    vector <vector <int>> adj(n + 1);
    vector <int> vis(n + 1);
  
    for(int u, v, i = 0; i < m; ++i){
        cin >> u >> v;

        adj[u].emplace_back(v);
        adj[v].emplace_back(u);
    }

    function <void(int, int)> dfs = [&](int u, int team){
        if (vis[u] == team) return;

        if (vis[u]){
            cout << "IMPOSSIBLE";
            exit(0);
        }

        vis[u] = team;
        team = !(team - 1) + 1;

        for(int& v: adj[u]) dfs(v, team);    
    };

    for(int i = 1; i <= n; ++i){
        if (!vis[i]) dfs(i, 1);
    }

    for (int i = 1;  i <= n; ++i)
        cout << vis[i] << ' ';
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
}
