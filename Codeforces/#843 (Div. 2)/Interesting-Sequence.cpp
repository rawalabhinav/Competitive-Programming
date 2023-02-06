#include <bits/stdc++.h>
using namespace std;

#ifdef RAWAL
    #include <Collections/debug.h>
#endif

#define int long long int

void solve(){
    int n, x; cin >> n >> x;

    if ((n & x) != x or (x and __builtin_clzll(x) > __builtin_clzll(n))){
        cout << "-1\n"; return;
    }

    if (!n or n == x){
        cout << n << '\n'; return;
    }

    if (!x){
        int index = 64 - __builtin_clzll(n);
        cout << (1ll << index) << '\n'; return;
    }

    int p = 0, set = 0;
    for(int m = n, y = x; m and y; (m >>= 1), (y >>= 1)){
        if (!(m & 1)){
            if (!p and set) set = 0;
            continue;
        }
        
        if ((y & 1)){
            if (set){
                cout << "-1\n"; return;
            } p = 1;
        } 
        
        else if(p){
            cout << "-1\n"; return;
        }

        else set = 1;
    }

    int sum = 0, index = 0;
    for(int m = n, y = x, i = 0; y and !(y & 1); ++i, (p <<= 1), (y >>= 1), (m >>= 1)){
        sum += (m & 1) * p;

        if ((m & 1)) index = i;
    }

    ++index; 
    cout << n + (1ll << index) - sum << '\n';
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin >> t;
    while(t--) solve();
}