#include <bits/stdc++.h>
using namespace std;

#ifdef RAWAL
    #include <Collections/debug.h>
#endif

#define int long long int
const int inf = 1e15;

int n, m; 
vector <vector<pair <int, int>>> adj;

void dijkstra(int u){
    set <pair <int, int>> s, f;
    vector <int> d(n + 1, inf), simple(n + 1, inf), vis(n + 1);

    simple[u] = 0;
    f.insert({0, u});

    while(!f.empty()){
        int v = f.begin() -> second;

        f.erase(f.begin());
        if (vis[v]) continue;

        for(auto& [x,w]: adj[v]){
            if (simple[v] + w < simple[x]){
                simple[x] = simple[v]+ w;
                f.insert({simple[x], x});
            }
        } vis[v] = 1;
    }

    d[u] = 0;
    s.insert({0, u});
    fill(vis.begin(), vis.end(), 0);

    while(!s.empty()){
        int v = s.begin() -> second;

        s.erase(s.begin());
        if (vis[v]) continue;

        for(auto& [x, w]: adj[v]){
            if (simple[v] + w / 2 < d[x]){
                d[x] = simple[v] + w / 2;
                s.insert({d[x], x});
            }

            if (d[v] + w < d[x]){
                d[x] = d[v] + w;
                s.insert({d[x], x});
            } 
            
        } vis[v] = 1;
    } cout << d[n]; exit(0);
}

void solve(){
    cin >> n >> m;

    adj.resize(n + 1);
    for(int u, v, w, i = 0; i < m; ++i){
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
    }
    
    dijkstra(1);
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
}