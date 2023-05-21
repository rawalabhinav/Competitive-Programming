#include <bits/stdc++.h>
using namespace std;

#ifdef RAWAL
    #include <Collections/debug.h>
#endif

#define int long long int

void solve(){
    int n; cin >> n;

    int a[n];
    for(int& e: a) cin >> e;

    vector <int> m = {a[0]};
    for(int i = 1; i < n; ++i){
        auto it = lower_bound(m.begin(), m.end(), a[i]);
        (it != m.end()) ? *it = a[i] : m.emplace_back(a[i]);
    } 
    
    cout << m.size();
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
}