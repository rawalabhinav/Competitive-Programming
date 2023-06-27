#include <bits/stdc++.h>
using namespace std;

#ifdef RAWAL
    #include <Collections/debug.h>
#endif

#define int long long int

inline bool isprime(const int& x){
    for(int i = 2; i * i <= x; ++i){
        if (x % i == 0) return false;
    } return true;
}

void solve(){
    int n, m; cin >> n >> m;
    
    if (!isprime(m)){
        for(int i = 0; i < n; ++i){
            for(int j = 1; j <= m; ++j){
                cout << j + i * m << ' ';
            } cout << '\n';
        } return;
    }

    if (!isprime(n)){
        for(int i = 1; i <= n; ++i){
            for(int j = 0; j < m; ++j){
                cout << i + j * n << ' ';
            } cout << '\n';
        } return;
    }

    for(int i = 1; i <= n; i += 2){
        for(int j = i * m - m + 1; j <= i * m; ++j){
            cout << j << ' ';
        } cout << '\n';
    }

    for(int i = 2; i <= n; i += 2){
        for(int j = i * m - m + 1; j <= i * m; ++j){
            cout << j << ' ';
        } cout << '\n';
    }
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin >> t;
    while(t--) solve();
}