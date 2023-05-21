#include <bits/stdc++.h>
using namespace std;

#ifdef RAWAL
    #include <Collections/debug.h>
#endif

#define int long long int
constexpr int mod = 1e9 + 7;

int n, dp[1000000];

constexpr void precompute(){
    dp[0] = 2;
    int slab = 1;

    for(int i = 1; i < 1e6; ++i){
        dp[i] = (5 * dp[i - 1] - 2 * slab + 2 * mod) % mod;
        slab = (slab + dp[i - 1]) % mod;
    }
}

inline void solve(){
    cin >> n; cout << dp[n - 1] << '\n';
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    precompute();

    int t; cin >> t;
    while(t--) solve();
}