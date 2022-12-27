#include <bits/stdc++.h>
using namespace std;

#ifdef RAWAL
    #include <Collections/debug.h>
#endif

#define int long long int

int s[725];
void square(){
    for(int i = 0; i < 725; ++i) s[i] = i * i;
    
}

void solve(){
    int n, e; cin >> n;

    int a[n];
    for(int& e: a) cin >> e;

    int f[4 * n + 4]{0};
    int ans = 0, p = 0; f[0] = 1;

    for(int i = 0; i < n; ++i){
        p = p ^ a[i];  int sq = 0;

        for(int j = 0; j * j < 2 * n + 1; ++j){
            if (f[p ^ s[j]])  sq += f[p ^ s[j]]; 
        }

        ++f[p];
        ans += i + 1 - sq;
    }

    cout << ans << '\n';
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    square();

    int t; cin >> t;
    for(; t; --t) solve();
}