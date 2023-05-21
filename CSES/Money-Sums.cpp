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

    int m = accumulate(a, a + n, 0ll);
    int dp[m + 1]{0};

    dp[0] = 1;
    for(int i = 0; i < n; ++i){
        for(int j = m - a[i]; j > - 1; --j){
            if (dp[j]) dp[j + a[i]] = 1;
        }
    }

    cout << accumulate(dp + 1, dp + m + 1, 0ll) << '\n';
    for(int i = 1; i <= m; ++i){
        if (dp[i]) cout << i << ' ';
    }
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
}