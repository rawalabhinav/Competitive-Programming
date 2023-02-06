#include <bits/stdc++.h>
using namespace std;

#ifdef RAWAL
    #include <Collections/debug.h>
#endif

#define int long long int

void solve(){
    int a, b; cin >> a >> b;

    if (b > a) cout <<  !((b - a) % 2) + 1 << '\n';
    else if (b == a) cout << "0\n";
    else cout << (a - b) % 2 + 1 << '\n';
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin >> t;
    while(t--) solve();
}