#include <bits/stdc++.h>
using namespace std;

#ifdef RAWAL
    #include <Collections/debug.h>
#endif

#define int long long int

void solve(){
    int n; cin >> n;

    (n & 1) ? cout << "-1\n" :cout << "1 " << n / 2 << '\n';
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; 
    for(cin >> t; t; --t) solve();
}