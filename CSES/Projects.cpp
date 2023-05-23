#include <bits/stdc++.h>
using namespace std;

#ifdef RAWAL
    #include <Collections/debug.h>
#endif

#define int long long int

void solve(){
    int n; cin >> n;

    array <int, 3> a[n];
    int s[n]{}; 

    for(auto&[s, e, p]: a) cin >> s >> e >> p;
    sort(a, a + n);

    int dp[n + 1]{0};
    for(int i = n - 1; i > -1; --i){
        int j = upper_bound(s, s + n, a[i][1]) - s;

        dp[i] =  max(dp[i + 1], dp[j] + a[i][2]);
        s[i] = a[i][0];
    } cout << dp[0];
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
}