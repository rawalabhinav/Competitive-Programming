#include <bits/stdc++.h>
using namespace std;

#ifdef RAWAL
    #include <Collections/debug.h>
#endif

#define int long long int

vector <vector <int>> adj;
vector <int> d, c;

void dfs(int u){
    if (d[u] > -2) return;

    d[u] = -1;
    for(int& v: adj[u]){
        dfs(v);

        if ((d[v] > -1) + d[v] > d[u]){
            d[u] = (d[v] > -1) + d[v];
            c[u] = v;
        }
    }
}

void solve(){
    int n, m; cin >> n >> m;

    adj.resize(n + 1); d.assign(n + 1, -2);
    c.resize(n + 1); d[n] = 0;

    for(int u, v, i = 0; i < m; ++i){
        cin >> u >> v;
        adj[u].emplace_back(v);
    }

    dfs(1);
    if (d[1] < 0){
        cout << "IMPOSSIBLE"; return;
    } 
  
    cout << d[1] + 1 << '\n';
    for(int u = 1; u != n; u = c[u]){
        cout << u << ' ';
    } cout << n << ' ';
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
}