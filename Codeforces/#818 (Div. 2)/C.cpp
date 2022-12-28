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

    int b[n];
    for(int& e: b) cin >> e;

    for(int i = 0; i < n; ++i){
        if (a[i] > b[i]){
            cout << "NO\n"; return;
        }

        if (a[i] == b[i]) continue;

        if (b[i] > b[(i + 1) % n] + 1){
            cout << "NO\n"; return;
        }
    }
    
    cout << "YES\n";
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin >> t;
    while(t--) solve();
}