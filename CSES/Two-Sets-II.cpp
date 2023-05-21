#include <bits/stdc++.h>
using namespace std;

#ifdef RAWAL
    #include <Collections/debug.h>
#endif

#define int long long int
constexpr int mod = 1e9 + 7;

void solve(){
    int n; cin >> n;

    int sum = n * n + n;
    if (sum % 4){
        cout << 0; exit(0);
    }

    int dp[sum / 4 + 1]{0};
    dp[sum / 4] = 1;

    for(int i = 1; i <= n; ++i){
        for(int j = i; j <= sum / 4; ++j){
            if (dp[j]) dp[j - i] = (dp[j - i] + dp[j]) % mod;
        }
    }

    cout << (dp[0] * 500000004) % mod;;
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
}