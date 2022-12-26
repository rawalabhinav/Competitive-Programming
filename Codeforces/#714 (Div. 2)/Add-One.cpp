#include <bits/stdc++.h>
using namespace std;

#ifdef RAWAL
    #include <Collections/debug.h>
#endif

#define int long long int
const int mod = 1e9 + 7, M = 2e5 + 1;

int dp[2][M];

int memo(int d, int m){
    if (m < 10 - d) return 0;
    
    if (dp[d][m]) return dp[d][m];
    
    return dp[d][m] =  (1 + memo(1, m - 10 + d) + memo(0, m - 10 + d)) % mod; 
}

void solve(){
    int n, m; cin >> n >> m;

    int f[10]{0};
    for(; n; n /= 10) ++f[n % 10];

    int sum = 0;
    for(int i = 0; i < 10; ++i){
        if (!f[i]) continue;

        sum += f[i] * (1 + !(m < 10 - i) + memo(1, m - 10 + i) + memo(0, m - 10 + i));
        sum = sum % mod;
    }

    cout << sum << '\n';
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin >> t;
    while(t--) solve();
}