#include <bits/stdc++.h>
using namespace std;

#ifdef RAWAL
    #include <Collections/debug.h>
#endif

#define int long long int

void solve(){
    int n, m, p, b, x; cin >> n >> m >> p >> b;

    int tok[n + 1];
    for(int i = 0; i < n; ++i){
        cin >> x; tok[x] = 1;
    }

    int bon[n + 1];
    for(int i = 0; i < n; ++i){
        cin >> x; bon[x] = 1;
    }

    vector <vector <int> adj(n + 1);
    for(int u, v, i = 0; i < m; ++i){
        cin >> u >> v;

        adj[u].emplace_back(v);
        adj[v].emplace_back(u);
    }

    

}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin >> t;
    while(t--) solve();
}