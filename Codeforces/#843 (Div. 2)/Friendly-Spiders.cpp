#include <bits/stdc++.h>
using namespace std;

#ifdef RAWAL
    #include <Collections/debug.h>
#endif

#define int long long int
const int high = 3e5;

void solve(){
    int n, e; cin >> n;

    map <int, int> m;
    for(int i = 0; i < n; ++i){
        cin >> e; m[e] = i;
    }

}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin >> t;
    while(t--) solve();
}