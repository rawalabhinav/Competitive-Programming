#include <bits/stdc++.h>
using namespace std;

#ifdef RAWAL
    #include <Collections/debug.h>
#endif

#define int long long int

void solve(){
    int n; cin >> n;

    int a[n];
    for(int& e: a) cin >> e;

    int p = a[0], m = *max_element(a, a + n);
    if (p < m){
        cout << m - p + 1 << '\n';
        return;
    }

    int freq = 0;
    for(int i = 0; i < n; ++i){
        if (a[i] == p) ++freq;
    }

    cout << ((freq > 1) ? 1 : 0) << '\n';


}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
}