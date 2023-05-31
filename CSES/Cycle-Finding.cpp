#include <bits/stdc++.h>
using namespace std;

#ifdef RAWAL
    #include <Collections/debug.h>
#endif

#define int long long int
constexpr int inf = 1e16;

void solve(){
    int n, m, f; cin >> n >> m;

    vector <tuple <int, int, int>> edge(m);
    vector <int> d(n + 1, inf), p(n + 1), ans; 
    
    d[1] = 0;
    for(auto&[u, v, w]: edge) cin >> u >> v >> w;

    /*
    * The loop ensures the parent of any negative
    * cycle after n iterations is in the cycle itself.
    */
    
    for(int i = 0; i < n; ++i){
        f = 0;
        for(auto& [u, v, w]: edge){
            if (d[u] + w < d[v]){
                d[v] = d[u] + w;
                p[v] =  u, f = v;
            }
        }
    }

    if (!f){
        cout << "NO\n"; return;
    }

    /* The last updated node f can be traced back to the 
    * closest node of the cycle which updates it, 
    * in atmost n steps.
    */
    for(int i = 0; i < n; f = p[f], ++i);

    for(int u = f; u != f or ans.size() < 2; u = p[u]){
        ans.emplace_back(u);
    }

    reverse(ans.begin(), ans.end());

    cout << "YES\n";
    for(int& e: ans) cout << e << ' ';
    cout << ans[0];
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    solve();
}


