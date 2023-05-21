#include <bits/stdc++.h>
using namespace std;

#ifdef RAWAL
    #include <Collections/debug.h>
#endif

#define int long long int

void solve(){
    int n, k; cin >> n >> k;

    vector <pair <int, int>> v(n);
    for(auto &[s, e]: v) cin >> e >> s;
    
    sort(v.begin(), v.end());
    multiset <int> m;

    for(int i = 0; i < k; m.insert(0), ++i);

    int ans = 0;
    for(int i = 0; i < n; ++i){
        auto it = m.upper_bound(v[i].second);

        if (it == m.begin()) continue;

        ++ans;
        m.erase(--it);
        m.insert(v[i].first);
    }

    cout << ans << ' ';
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
}