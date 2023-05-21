#include <bits/stdc++.h>
using namespace std;

#ifdef RAWAL
    #include <Collections/debug.h>
#endif

#define int long long int

void solve(){
    int n; cin >> n;

    vector <int> dp(n + 1, n + 1);
    dp[n] = 0;

    for(int i = n; i > 0; --i){
        if (dp[i] > n) continue;

        for(int m = i; m; m /= 10){
            int j = m % 10;

            if (!j or i - j < 0) continue;
            dp[i - j] = min(dp[i - j], dp[i] + 1);
        }
    }

    cout << dp[0];
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
}