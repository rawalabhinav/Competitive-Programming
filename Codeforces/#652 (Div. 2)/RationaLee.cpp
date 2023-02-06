#include <bits/stdc++.h>
using namespace std;

#ifdef RAWAL
    #include <Collections/debug.h>
#endif

#define int long long int

void solve(){
    int n, k, sum = 0; cin >> n >> k;

    int a[n];
    for(int& e: a) cin >> e;

    int w[k];
    for(int& e: w) cin >> e;

    sort(a, a + n, greater<int>()); 
    sort(w, w + k);

    for(int i = 0; i < k; ++i){
        sum += a[i];

        if (w[i] == 1) sum += a[i];
    }

    for(int& e: w){
        if (e < 2) continue;

        sum += a[k + e - 2];
        k += e - 1;
    }

    cout << sum << '\n';
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin >> t;
    while(t--) solve();
}