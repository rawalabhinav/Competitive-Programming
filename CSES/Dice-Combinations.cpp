#include <bits/stdc++.h>
using namespace std;

#ifdef RAWAL
    #include <Collections/debug.h>
#endif

#define int long long int
constexpr int mod =  1e9 + 7;

void solve(){
    int n; cin >> n;

    int p[n + 1]{0}; p[n] = 1;
    for(int i = n; i > 0; --i){
        for(int j = 1; j < 7; ++j){
            if (i - j < 0) break;
            p[i - j] = (p[i] + p[i - j]) % mod; 
        }
    } cout << p[0];
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
}