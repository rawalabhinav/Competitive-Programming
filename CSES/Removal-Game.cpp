#include <bits/stdc++.h>
using namespace std;

#ifdef RAWAL
    #include <Collections/debug.h>
#endif

#define int long long int

void solve(){
    int n; cin >> n;

    int a[n];
    for(int& e: a) cin >> e;

    int b = (n & 1);
    int dp[n][n] = {};

    if (b) for(int i = 0; i < n; ++i){
        dp[i][i] = a[i];
    }

    for(int i = n - 1; i > -1; --i){
        for(int j = i + 1; j < n; ++j){
            if (b - ((i + j) & 1)){
                dp[i][j] = max(dp[i + 1][j] + a[i], dp[i][j - 1] + a[j]);
            } else {
                dp[i][j] = min(dp[i + 1][j], dp[i][j - 1]);
            }
        }
    }

    cout << dp[0][n - 1];
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
}