#include <bits/stdc++.h>
using namespace std;

#ifdef RAWAL
    #include <Collections/debug.h>
#endif

#define int long long int

void solve(){
    int n, r, u, v; cin >> n >> r;

    int c[n - 1];
    for(int& e: c) cin >> e;

    vector <vector <int>> adj(n + 1);
    for(int i = 1; i < n; ++i){
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