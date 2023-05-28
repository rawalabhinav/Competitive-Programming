#include <bits/stdc++.h>
using namespace std;

#ifdef RAWAL
    #include <Collections/debug.h>
#endif

#define int long long int
/* x < w[i] implies we need a new elevator ride

Information our mask has:
    1. Number of people left with their resp weights
    … O(logn)
    2. ̐How many elevator rides there have been already
    … O(n)
*/

int n, global_x;
vector <int> w, dp;

int calls = 0;

int f(int mask, int x){
    if (x < 0) return n + 1;
    if (calls++ > 1e5) {
        cout << "hello";
        debug(dp);
        exit(0);
    }
    if (dp[mask] <= n) return dp[mask];
    for(int i = 0; i < n; ++i){
        if ((1 << i) & mask) continue;

        if (w[i] > x){
            for(; i < n; ++i) dp[mask] = min(dp[mask], 1 + f(mask ^ (1 << i), global_x - w[i]));
            break;
        } 
         
        dp[mask] = min(dp[mask], f(mask ^ (1 << i), x - w[i]));
    } 

    return dp[mask];
}

void solve(){
    cin >> n >> global_x;

    w.resize(n), dp.assign((1 << n), n + 1);
    for(int&e: w) cin >> e;

    sort(w.begin(), w.end());
    cout << f(0, global_x);
    
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
}