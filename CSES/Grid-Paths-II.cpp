#include <bits/stdc++.h>
using namespace std;

#ifdef RAWAL
    #include <Collections/debug.h>
#endif

#define int long long int
constexpr int mod = 1e9 + 7;

void solve(){
    int n; cin >> n;

    string s[n];
    for(auto& e: s) cin >> e;
    
    int dp[n]{0};
    dp[n - 1] = s[n - 1][n - 1] == '.';

    for(int i = n - 1; i > -1; --i){
        for(int j = n - 1; j > -1; --j){
            if (s[i][j] != '.') dp[j] = 0;
            
            if (j) dp[j - 1] = (dp[j] + dp[j - 1]) % mod;
        }
    }

    cout << dp[0];
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
}