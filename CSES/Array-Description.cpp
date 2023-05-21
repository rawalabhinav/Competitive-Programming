#include <bits/stdc++.h>
using namespace std;

#ifdef RAWAL
    #include <Collections/debug.h>
#endif

#define int long long int
constexpr int mod = 1e9 + 7;

vector <vector <int>> dp;
void solve(){
    int n, m; cin >> n >> m;

    int a[n];
    for(int& e: a) cin >> e;

    vector <vector <int>> dp(n, vector <int>(m + 2));

    if (a[n - 1]) dp[n - 1][a[n - 1]] = 1;
    else dp[n - 1] = vector <int>(m + 2, 1);

    int sign[] = {-1, 0, 1};
    for(int i = n - 1; i > 0; --i){
        if (a[i]){
            for(int& j: sign){
                dp[i - 1][a[i] + j] = (dp[i - 1][a[i] + j] + dp[i][a[i]]) % mod;;
            }
            continue;
        }

        for(int j = 1; j <= m; ++j){
            for(int& k: sign){
                dp[i - 1][j + k] = (dp[i - 1][j + k] + dp[i][j]) % mod;;
            }
        }
    }

    if (a[0]){
        cout << dp[0][a[0]];
        return;
    }

    int sum = 0;
    for(int i = 1; i <= m; ++i){
        sum = (sum + dp[0][i]) % mod;
    } cout << sum;
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
}