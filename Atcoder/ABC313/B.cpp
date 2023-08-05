#include <bits/stdc++.h>
using namespace std;

#ifdef RAWAL
    #include <Collections/debug.h>
#endif

#define int long long int

vector <vector <int>> adj;

void solve(){
    int n, m; cin >> n >> m;

    int sup[n + 1]{}; sup[0] = 1;
    for(int u, v, i = 0; i < m; ++i){
        cin >> u >> v;
        sup[v] = u;
    }

    int freq = 0, maxi = 0;
    for(int i = 1; i <= n; ++i){
        if (!sup[i]){
            ++freq, maxi = i;
        }
    }

    cout << (freq > 1 ? -1 : maxi ) ;
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
}