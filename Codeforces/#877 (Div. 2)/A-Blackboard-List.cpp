#include <bits/stdc++.h>
using namespace std;

#ifdef RAWAL
    #include <Collections/debug.h>
#endif

#define int long long int

void solve(){
    int n; cin >> n;

    int neg = 0, high = -1e9;
    for(int a, i = 0; i < n; ++i){
        cin >> a;

        a < 0 ? neg = min(neg, a) : high = max(high, a);
    }

    cout << ((neg) ? neg : high) << '\n';
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin >> t;
    while(t--) solve();
}