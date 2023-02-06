#include <bits/stdc++.h>
using namespace std;

#ifdef RAWAL
    #include <Collections/debug.h>
#endif

#define int long long int

void solve(){
    int x; cin >> x;

    if ((x & 1)){
        cout << "-1\n"; return;
    }

    int p = (x & 1);
    for(int y = (x >> 1); y; y >>= 1){
        if ((y & 1) && p){
            cout << "-1\n"; return;
        } p = (y & 1);
    }

    int n = 63 - __builtin_clzll(x);
    int a = 0, b = 0, c[n + 1]{0}; 

    for(int y = x, i = 0; y; c[i] = (y & 1), (y >>= 1), ++i);

    for(; n > 0; --n){
        if (!c[n]) continue;

        a += (1 << n) + (1 << (n - 1));
        b += (1 << (n - 1));
    }
    
    cout << a << ' ' << b << '\n';
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin >> t;
    while(t--) solve();
}