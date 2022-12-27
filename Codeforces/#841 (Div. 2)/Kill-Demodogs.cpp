#include <bits/stdc++.h>
using namespace std;

#ifdef RAWAL
    #include <Collections/debug.h>
#endif

#define int long long int
const int mod = 1e9 + 7;

void solve(){
    int n; cin >> n;
    int s = ((n * n) % mod + n) % mod;
    cout << ((( s * (4 * n - 1)) % mod) * 337 ) % mod <<'\n';
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin >> t;
    while(t--) solve();
}