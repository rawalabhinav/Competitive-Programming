#include <bits/stdc++.h>
using namespace std;

#ifdef RAWAL
    #include <Collections/debug.h>
#endif

#define int long long int

void solve(){
    int n, i, j, k; cin >> n;

    for(int p, x = 0; x < n; ++x){
        cin >> p;

        if (p == 1)      i = x;
        else if (p == 2) j = x;
        else if (p == n) k = x;
    }

    if (j > k){
        if (k) cout << k << ' ' << i + 1 << '\n';
        else if (i < j) cout << k + 1 << ' ' << i + 1 << '\n';
        else cout << k + 1 << ' ' << j + 1 << '\n';
    }

    else if (k < n - 1) cout << k + 2 << ' ' << i + 1 << '\n';
    else if (i < j) cout << k + 1 << ' ' << j + 1 << '\n';
    else cout << i + 1 << ' ' << k + 1 << '\n';
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin >> t;
    while(t--) solve();
}