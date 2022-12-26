#include <bits/stdc++.h>
using namespace std;

#ifdef RAWAL
    #include <Collections/debug.h>
#endif

#define int long long int
const int mod = 1e9 + 7, N = 2e5 + 1;

int f[N];
void fac(){
    f[0] = 1;
    for(int i = 1; i < N; ++i){
        f[i] = (f[i - 1] * i) % mod;
    }
}

void solve(){
    int n; cin >> n;

    int a[n]; 
    for(int& e: a) cin >> e;

    int m = *min_element(a, a + n);
    int z = count(a, a + n, m);

    for(int& e: a){
        if ((e & m) != m){
            cout << "0\n"; return;
        }
    }
    
    cout << (((z * (z - 1)) % mod) * f[n - 2]) % mod << '\n';
    return;
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    fac();

    int t; cin >> t;
    while(t--) solve();
}