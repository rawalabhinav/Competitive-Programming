#include <bits/stdc++.h>
using namespace std;

#ifdef RAWAL
    #include <Collections/debug.h>
#endif

#define int long long int

void solve(){
    int n, k; cin >> n >> k;

    int a[n];
    for(int& e: a) cin >> e;

    auto good = [&](int mid, int g = 1){
        for(int i = 0, s = 0; i < n; ++i){
            if (a[i] > mid) return false;

            if (s + a[i] <= mid) s += a[i];
            else if (g < k) ++g, s = a[i];
            else return false;
        } return true;
    };

    int l = 0, r = accumulate(a, a + n, 0ll);
    for(int m = (l + r) / 2; l < r; m = (l + r) / 2){
        good(m) ? r = m : l = m + 1;
        
    } cout << l;
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
}