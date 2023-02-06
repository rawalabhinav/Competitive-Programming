#include <bits/stdc++.h>
using namespace std;

#ifdef RAWAL
    #include <Collections/debug.h>
#endif

#define int long long int

void solve(){
    int n, ans = 0; cin >> n;

    int a[n];
    for(int& e: a) cin >> e;

    multiset <int> m(a, a + n);
    set <int> s(a, a + n);

    while(!m.empty()){
        int x = *(s.begin());

        for(int y = x; s.find(y) != s.end(); ++y){
            auto it = m.find(y);

            if (it != m.end()) m.erase(it);

            it = m.find(y);
            if (it == m.end()) s.erase(y);
        } ++ans;
    }
    cout << ans << '\n';

}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin >> t;
    while(t--) solve();
}
