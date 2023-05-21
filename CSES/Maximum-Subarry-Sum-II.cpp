#include <bits/stdc++.h>
using namespace std;

#ifdef RAWAL
    #include <Collections/debug.h>
#endif

#define int long long int

void solve(){
    int n, a, b; cin >> n >> a >> b;

    int v[n];
    for(int & e: v) cin >> e;

    if (b < 2){
        cout << *max_element(v, v + n);
        return;
    }

    int p[n + 1]; p[0] = 0;
    for(int i = 0; i < n; ++i){
        p[i + 1] = v[i] + p[i];
    }

    multiset <int> m;
    m.insert(0);

    int ans = -1e17;

    for(int i = a; i <=n; ++i){
        ans = max(ans, p[i] - *m.begin());

        if (i >= b) m.erase(m.find(p[i - b]));
        m.insert(p[i - a + 1]);
    }

    cout << ans << ' ';
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
}