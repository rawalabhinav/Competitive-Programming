#include <bits/stdc++.h>
using namespace std;

#ifdef RAWAL
    #include <Collections/debug.h>
#endif

#define int long long int

void solve(){
    int n, x; cin >> n >> x;

    int a[n];
    for(int& e: a) cin >> e;

    vector <int> dp(x + 1, x + 1);
    dp[x] = 0;

    for(int i = x; i > 0; --i){
        for(int& e: a){
            if (i - e < 0) continue;

            dp[i - e] = min(dp[i - e], dp[i] + 1);
        }
    }
    
    cout << (dp[0] != x + 1 ? dp[0] : -1);
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
}