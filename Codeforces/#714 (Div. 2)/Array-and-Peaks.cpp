#include <bits/stdc++.h>
using namespace std;

#ifdef RAWAL
    #include <Collections/debug.h>
#endif

#define int long long int

void solve(){
    int n, k; cin >> n >> k;

    if (k > (n - 1) / 2){
        cout << "-1\n"; return;
    }


    if (not k){
        for(int  i = 1; i  < n + 1; ++i) cout << i << ' ';
        cout << '\n'; return;
    }

    vector <int> p(n); 

    cout << 1 << ' ';
    for(int j = 0; j < k; ++j){
        cout <<  2 * j + 3 << ' ' << 2 * j + 2 << ' ';
    }

    for(int i = 2 * k + 2; i < n + 1; ++i){
        cout << i << ' ';
    } cout << '\n';

}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin >> t;
    while(t--) solve();
}