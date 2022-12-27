#include <bits/stdc++.h>
using namespace std;

#ifdef RAWAL
    #include <Collections/debug.h>
#endif

#define int long long int

void solve(){
    int n, m, u, v, w; cin >> n >> m;

    vector <vector <pair <int, int>>> adj(n + 1);
    for(int i = 0; i < m; ++i){

        cin >> u >> v;
        w = __gcd(u, v);

        adj[u].push_back({u, w});
        adj[v].push_back({v, w});  
    }

}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin >> t;
    while(t--) solve();
}