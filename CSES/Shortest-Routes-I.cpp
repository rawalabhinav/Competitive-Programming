#include <bits/stdc++.h>
using namespace std;

#ifdef RAWAL
    #include <Collections/debug.h>
#endif

#define int long long int
const int inf = 1e18;

int n, m;
vector <vector <pair <int, int>>> adj;

void dijkstra(int u){
    set <pair <int, int>> s;
    vector <int> d(n + 1, inf), vis(n + 1);

    d[u] = 0;
    s.insert({0, u});

    while(!s.empty()){
        int v = s.begin() -> second;

        s.erase(s.begin());
        if (vis[v]) continue;

        for(auto& [x,w]: adj[v]){
            if (d[v] + w < d[x]){
                d[x] = d[v] + w;
                s.insert({d[x], x});
            }
        } vis[v] = 1;
    }

    for(int i = 1; i <= n; cout << d[i] << ' ', ++i);
}

void solve(){
    cin >> n >> m;

    adj.resize(n + 1);
    int u, v, w;

    for(int i = 0; i < m; ++i){
        cin >> u >> v >> w;

        adj[u].push_back({v,w});
    }

    dijkstra(1);
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
}