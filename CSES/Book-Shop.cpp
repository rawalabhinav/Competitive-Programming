#include <bits/stdc++.h>
using namespace std;

#ifdef RAWAL
    #include <Collections/debug.h>
#endif

#define int long long int

void solve(){
    int n, x; cin >> n >> x;

    int h[n], s[n];
    for(int & e: h) cin >> e;
    for(int & e: s) cin >> e;

    vector <int> dp(x + 1, -1);
    dp[x] = 0;

    for(int j = 0; j < n; ++j){
        for(int i = h[j]; i <= x; ++i){
            if (dp[i] > -1) dp[i - h[j]] = max(dp[i - h[j]], dp[i] + s[j]);
        }
    }

    cout << *max_element(dp.begin(), dp.end());
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
}