#include "bits/stdc++.h"
using namespace std;

#ifdef RAWAL
    #include <Collections/debug.h>
#endif

#define int long long int

void solve(){
    int n, m; cin >> n >> m;

    vector <int> dp(n + 1);
    for (int i = n - 1; i > 0; i--){
        int sum = 0;
        for (int k = 1; k * i <= n; k++)
            sum += dp[k * i];

        int sz = n / i;
        dp[i] = sz * (sz - 1) / 2 - sum;
    }

    int cost = 0;
    for (int g = n; g > 1 and m > 0; g--){
        if (dp[g] == 0 or dp[g] < g - 1)
            continue;

        int have = dp[g] / (g - 1);
        if (have * (g - 1) > m){
            int y = m / (g - 1);
            m -= y * (g - 1);
            cost += y * g;
        }

        else{
            m -= have * (g - 1);
            cost += have * g;
        }
    }

    (m > 0) ? cout << "-1\n" : cout << cost << "\n";
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;cin >> t;
    while (t--) solve();
}