#include <bits/stdc++.h>
using namespace std;

#ifdef RAWAL
    #include <Collections/debug.h>
#endif

#define int long long int

void solve(){
    int n, freq = 0; cin >> n;

    int a[n];
    for(int& e: a) cin >> e;

    int m = *max_element(a, a + n);
    if (a[0] < m){
        cout << a[0] - p + 1 << '\n';
        return;
    }

    for(int i = 0; i < n; ++i){
        if (a[i] == a[0]) ++freq;
    }

    cout << (freq > 1)  << '\n';
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
}