#include <bits/stdc++.h>
using namespace std;

#ifdef RAWAL
    #include <Collections/debug.h>
#endif

#define int long long int

void solve(){
    int n, k, r, c; cin >> n >> k >> r >> c;

    vector <string> m(n, string(n, '.'));

    for(int i = r - 1; i < n; i += k){
        m[i][c - 1] = 'X';
    }

    for(int i = r - 1; i > - 1; i -= k){
        m[i][c - 1] = 'X';
    }

    for(int i = c; i < n; ++i){
        for(int j = 0; j < n; ++j){
            m[j][i] = m[(j - 1 + n) % n][(i - 1 + n) % n];
        }
    }

    for(int i = c - 2; i > - 1; --i){
        for(int j = 0; j < n; ++j){
            m[j][i] = m[(j + 1) % n][(i + 1) % n];
        }
    }

    for(string& s: m) cout << s << '\n';
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin >> t;
    while(t--) solve();
}