#include <bits/stdc++.h>
using namespace std;

#ifdef RAWAL
    #include <Collections/debug.h>
#endif

#define int long long int

void solve(){
    int n, m, k; cin >> n >> m >> k;

    vector <vector <pair <int, int>>> adj(n + 1);
    for(int u, v, w, i = 0; i < m; ++i){
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
    }

    vector <multiset <int>> vis(n + 1);
    multiset <pair <int, int>> q;

    q.insert({0, 1});
    while(!q.empty()){
        auto [d, u] = *q.begin();

        q.erase(q.begin());
        if (vis[u].size() == k) continue;

        vis[u].insert(d);
        for(auto& [v, w]: adj[u]){
            q.insert({d + w, v});
        }
    }

    for(const int& e: vis[n]) cout << e << ' ';
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
}