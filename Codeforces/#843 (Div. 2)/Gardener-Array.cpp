#include <bits/stdc++.h>
using namespace std;

#ifdef RAWAL
    #include <Collections/debug.h>
#endif

#define int long long int
const int m = 2e5;

void solve(){
    int n, k; cin >> n;

    vector <int> c[n];
    map <int, int> f;

    for(auto& v: c){
        cin >> k; v = vector <int>(k);

        for(int&e: v){
            cin >> e; ++f[e];
        }
    }

    for(auto& v: c){
        int found = 1;

        for(int& e: v){
            if (f[e] > 1) continue;
            found = 0; break;
        }

        if (found){
            cout << "Yes\n"; return;
        }
    } cout << "No\n";
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin >> t;
    while(t--) solve();
}
