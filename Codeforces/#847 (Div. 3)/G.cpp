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

    int u, v;
    for(int  i = 0; i < m; ++i){

    }
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin >> t;
    while(t--) solve();
}