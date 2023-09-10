#include <bits/stdc++.h>
using namespace std;

#ifdef RAWAL
    #include <Collections/debug.h>
#endif

#define int long long int

int n, m;
vector <vector <int>> adj;
vector <int> vis, node;

void solve(){
    cin >> n >> m;

    adj.resize(n + 1), vis.resize(n + 1);
    for(int u, v, i = 0; i < m; ++i){
        cin >> u >> v;

        adj[u].emplace_back(v);
        adj[v].emplace_back(u);
    }

    queue <pair <int, int>> q;
    q.push({n, -1});

    while(!q.empty()){
        auto [u, p] = q.front();
        q.pop();

        if (vis[u]) continue;
        vis[u] = p;

        if (u != 1){
            for(int& v: adj[u]) q.push({v, u});
            continue;
        }

        for(; u != n; u = vis[u]){
            node.emplace_back(u);
        }

        cout << node.size() + 1 << '\n';
        for(int& e: node) cout << e << ' ';
        cout << n << '\n';

        return;
    }

    cout << "IMPOSSIBLE";
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
}