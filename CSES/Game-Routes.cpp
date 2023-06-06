#include <bits/stdc++.h>
using namespace std;

#ifdef RAWAL
    #include <Collections/debug.h>
#endif

#define int long long int
constexpr int mod =  1e9 + 7;

vector <vector <int>> adj;
vector <int> d;

int memo(int u){
    if (d[u] > -1) return d[u];

    d[u] = 0;
    for(int& v: adj[u]){
        d[u] = (d[u] + memo(v)) % mod;
    } return d[u];
}

void solve(){
    int n, m; cin >> n >> m;

    adj.resize(n + 1), d.assign(n + 1, -1);
    for(int u, v, i = 0; i < m; ++i){
        cin >> u >> v;
        adj[v].emplace_back(u);
    }

    d[1] = 1;
    cout << memo(n);
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
}