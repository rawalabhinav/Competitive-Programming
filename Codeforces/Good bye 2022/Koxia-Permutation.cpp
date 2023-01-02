#include <bits/stdc++.h>
using namespace std;

#ifdef RAWAL
    #include <Collections/debug.h>
#endif

#define int long long int

void solve(){
    int n, k; cin >> n >> k;

    int back = n, front = 1; --k;
    if (!k){
        for(int i = 0; i < n; ++i) cout << i + 1 << ' ';
        cout << '\n'; return;
    }
    for(int i = 0; i < n; i += 2 * k){

        for(int j = i; j < min(i + k , n); ++j){
            cout << (back--) << ' ';
        }

        for(int j = i + k; j < min(i + 2 * k, n); ++j){
            cout << (front++) << ' ';
        }
    } cout << '\n';
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin >> t;
    while(t--) solve();
}