#include <bits/stdc++.h>
using namespace std;

#ifdef RAWAL
    #include <Collections/debug.h>
#endif

#define int long long int
string s, t;

void solve(){
    cin >> s >> t;

    int n = s.length(), m = t.length();
    if (m > n){
        swap(s, t); swap(n, m);
    }

    vector <int> dp(m + 1);
    iota(dp.rbegin(), dp.rend(), 0ll);
    
    for(int i = n - 1; i > -1; dp[m] = n - i, --i){
        for(int j = m - 1, old = dp[m]; j > -1; --j){
            int current = dp[j];

            dp[j] = min({dp[j + 1] + 1, dp[j] + 1, old + (s[i] != t[j])});

            old = current;
        }
    }

    cout << dp[0];
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
}