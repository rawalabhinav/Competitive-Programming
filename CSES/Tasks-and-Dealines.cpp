#include <bits/stdc++.h>
using namespace std;

#ifdef RAWAL
    #include <Collections/debug.h>
#endif

#define int long long int

void solve(){
    int n, d, ans = 0; cin >> n;

    int f[n];
    for(int i = 0; i < n; ++i, ans += d){
        cin >> f[i] >> d;
    }

    sort(f, f + n);
    for(int i = 0; i < n; ++i){
        ans -= f[i] * (n - i);
    } cout << ans;
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
}
