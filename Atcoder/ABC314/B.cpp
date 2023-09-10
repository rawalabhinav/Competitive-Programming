#include <bits/stdc++.h>
using namespace std;

#ifdef RAWAL
    #include <Collections/debug.h>
#endif

#define int long long int

void solve(){
    int n, x; cin >> n;
    int bet[n][37], tot[n];

    for(int c, a, i = 0; i < n; ++i){
        cin >> c; 
        tot[i] = c;

        for(int j = 0; j < c; ++j){
            cin >> a; 
            bet[i][a] = 1;
        }
    }

    vector <int> tmp, ans;
    int mbet = 37; cin >> x;

    for(int i = 0; i < n; ++i){
        if (bet[i][x]){
            tmp.emplace_back(i);
            mbet = min(tot[i], mbet);
        }
    }

    for(int& e: tmp){
        if (tot[e] == mbet){
            ans.emplace_back(e + 1);
        }
    }

    cout << ans.size() << '\n';
    for(int& e: ans) cout << e << ' ';
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
}