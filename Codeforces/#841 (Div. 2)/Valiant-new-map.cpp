#include <bits/stdc++.h>
using namespace std;

#ifdef RAWAL
    #include <Collections/debug.h>
#endif

#define int long long int

void solve(){
    int n, m; cin >> m;

    int a[n][m], b[n][m];
    for(int i = 0; i < n; ++i){
        for(int j = 0; j < m; ++j){
            cin >> a[i][j]; 
            
            b[i][j] = min({a[i][j], n - i, m - j});
        }
    }

    int r[n][m]{0}, d[n][m]{0};
    for(int i = n - 1; i > -1; --i){
        for(int j = m - 1; j > -1; --j){
            // if ()
        }
    }
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin >> t;
    while(t--) solve();
}