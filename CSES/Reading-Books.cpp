#include <bits/stdc++.h>
using namespace std;

#ifdef RAWAL
    #include <Collections/debug.h>
#endif

#define int long long int

void solve(){
    int n, e; cin >> n;

    int sum = 0, m = 0;
    for(int i = 0; i < n; ++i){
        cin >> e; sum += e;
        m = max(m, e);
    }

    cout << max(2 * m, sum);
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
}