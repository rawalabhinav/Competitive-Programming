#include <bits/stdc++.h>
using namespace std;

#ifdef RAWAL
    #include <Collections/debug.h>
#endif

#define int long long int

void solve(){
    int a, b; cin >> a >> b;

    vector <vector <int>> dp(a + 1, vector <int>(b + 1, 10000));

    for(int j = 1; j <= b; ++j){
        for(int i = 1; i <= a; ++i){
            if (i == j){
                dp[i][j] = 0; continue;
            }

            for(int k = 1; k < i; ++k){
                dp[i][j] = min(dp[i][j], 1 + dp[i - k][j] + dp[k][j]);
            }

            for(int k = 1; k < j; ++k){
                dp[i][j] = min(dp[i][j], 1 + dp[i][j - k] + dp[i][k]);
            }
        }
    }

    cout << dp[a][b];
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
}