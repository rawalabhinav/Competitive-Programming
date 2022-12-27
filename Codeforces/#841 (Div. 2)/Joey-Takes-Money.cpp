#include <bits/stdc++.h>
using namespace std;

#ifdef RAWAL
    #include <Collections/debug.h>
#endif

#define int long long int

void solve(){
    int n, e; cin >> n;

    int ans = 1;
    for(int  i = 0; i < n; ++i){
        cin >> e; ans *= e;
    }

    cout << (ans + (n - 1) ) * 2022 << '\n';
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin >> t;
    while(t--) solve();
}
