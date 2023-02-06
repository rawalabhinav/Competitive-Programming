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

    sort(a, a + n);

    int cnt = 0;
    for(int i = 0, j = 0; i < n; ++i){
        if (a[i] - j == 0) continue;

        if (j < a[i] - 1) cnt += a[i] - 1 - j;
        ++j;
    }

    cout << cnt << '\n';
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin >> t;
    while(t--) solve();
}