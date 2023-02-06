#include <bits/stdc++.h>
using namespace std;

#ifdef RAWAL
    #include <Collections/debug.h>
#endif

#define int long long int

void solve(){
    int n; cin >> n;

    vector <vector <int>> a(n, vector <int>(n - 1));
    for(auto& v: a){
        for(int& e: v) cin >> e;
    }

    int x = a[0][0], s = 0, y;
    for(int i = 0; i < n; ++i){
        (a[i][0] == x) ? ++s : y = a[i][0];
    }

    if (s == 1) x = y;

    for(int i = 0; i < n; ++i){
        if (a[i][0] == x)continue;

        cout << x << ' ';
        for(int&e: a[i])  cout << e << ' ';
        cout << '\n'; return;
    }
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin >> t;
    while(t--) solve();
}