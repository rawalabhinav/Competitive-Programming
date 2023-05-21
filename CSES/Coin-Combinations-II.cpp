#include <bits/stdc++.h>
using namespace std;

#ifdef RAWAL
    #include <Collections/debug.h>
#endif

#define int long long int
constexpr int mod = 1e9 + 7;

void solve(){
    int n, x; cin >> n >> x;

    int a[n];
    for(int& e: a) cin >> e;

    sort(a, a + n);
    int dp[x + 1]{0};
    dp[x] = 1;

    for(int j = n - 1; j > -1; --j){
        for(int i = x; i > -1; --i){
            if (i - a[j] > -1 && dp[i]){
                dp[i - a[j]] = (dp[i - a[j]] + dp[i]) % mod;
            }
        }
    }
    
    cout << dp[0];
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
}