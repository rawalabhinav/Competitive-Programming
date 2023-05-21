#include <bits/stdc++.h>
using namespace std;

#ifdef RAWAL
    #include <Collections/debug.h>
#endif

#define int long long int
constexpr int mod =  1e9 + 7;

void solve(){
    int n, x; cin >> n >> x;

    int a[n];
    for(int& e: a) cin >> e;

    int p[x + 1]{0}; p[x] = 1;
    for(int i = x; i > 0; --i){
        for(int& e: a){
            if (i - e < 0) continue;
            p[i - e] = (p[i] + p[i - e]) % mod; 
        }
    } cout << p[0];
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
}