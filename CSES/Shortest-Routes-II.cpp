#include <bits/stdc++.h>
using namespace std;

#ifdef RAWAL
    #include <Collections/debug.h>
#endif

#define int long long int
const int inf = 1e17;

void solve(){
    int n, m, q; cin >> n >> m >> q;
    int u, v, w;

    vector <vector <int>> d(n + 1, vector <int>(n + 1, inf));
    for(int i = 1; i <= n; ++i) d[i][i] = 0;

    for(int i = 0; i < m; ++i){
        cin >> u >> v >> w;

        d[u][v] = min(d[u][v], w);
        d[v][u] = min(d[v][u], w);
    }

    for (int k = 1; k <= n; ++k){
        for(int i = 1; i <= n; ++i){
            for(int j = 1; j <= n; ++j){
                d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
            }
        }
    }

    for(; q; --q){
        cin >> u >> v;

        if (d[u][v] < inf){
            cout << d[u][v] << '\n';
        } else{
            cout << "-1\n";
        }
    }
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
}