#include <bits/stdc++.h>
using namespace std;

#ifdef RAWAL
    #include <Collections/debug.h>
#endif

#define int long long int

queue <int> q;
int n, m, nodes = 0;

void topo(){
    cin >> n >> m;
    
    vector <vector <int>> adj(n + 1);
    vector <int> tsort;

    for(int i = 0; i < m; ++i){
        int u, v; cin >> u >> v;

        adj[u].emplace_back(v);
    }

    int deg[n + 1]{0};
    for(int i = 1; i <= n; ++i){
        for(int& e: adj[i]) ++deg[e];
    }

    for(int i = 1; i <= n; ++i){
        if (!deg[i]) q.push(i);
    }

    while(!q.empty()){
        int u = q.front();
        q.pop();

        tsort.emplace_back(u);
        ++nodes;

        for(auto& e: adj[u]){
            if(--deg[e]) continue;
            q.push(e);
        } 
    }

    if (nodes != n){
        cout << "IMPOSSIBLE"; return;
    }

    for(int& e: tsort) cout << e << ' ';
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    topo();
}