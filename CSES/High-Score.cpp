#include <bits/stdc++.h>
using namespace std;

#ifdef RAWAL
    #include <Collections/debug.h>
#endif

#define int long long int
constexpr int inf = 1e16;

void solve(){
    int n, m; cin >> n >> m;
    
    vector <int> d(n + 1, inf); d[1] = 0;
    vector <tuple <int, int, int>> edge(m);

    for(auto& [u, v, w]: edge){
        cin >> u >> v >> w; w = -w;
    }

    for(int i = 1; i < n; ++i){
        for(auto& [u, v, w]: edge){
            if (d[u] != inf && d[u] + w < d[v]){
                d[v] = d[u] + w;
            }
        }
    }

    for(int i = 1; i < n; ++i){
        for(auto& [u, v, w]: edge){
            if (d[u] != inf && d[u] + w < d[v]){
                d[v] = -inf;
            }
        }
    }

    cout << (d[n] > -inf ? -d[n] : -1);
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
}