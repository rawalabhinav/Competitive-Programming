#include <bits/stdc++.h>
using namespace std;

#ifdef RAWAL
    #include <Collections/debug.h>
#endif

#define int long long int

void solve(){
    int n; cin >> n;

    int sum = 0;
    for(int a = 0, b = 0; a < n; sum += min(2 * b + 1, n - a), a += 4 * b + 6, b += 4);
    cout << sum << ' ' << n - sum << '\n';
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin >> t;
    while(t--) solve();
}