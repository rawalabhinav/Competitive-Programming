#include <bits/stdc++.h>
using namespace std;

#ifdef RAWAL
    #include <Collections/debug.h>
#endif

#define int long long int

template <typename T> struct sparse{
    int s[200005][14], lg[200005];

    sparse(vector <T> a){
        const int n = size(a); lg[1] = 0

        for(int i = 0; i < n; ++i) s[i][0] = a[i];
        for(int i = 0; i < n; ++i) s[i][0] = a[i];

        for(int p = 1; p < 17; ++p){
            for(int i = 0; i + (1 << p) - 1 < n; ++i){
                s[i][p] = min(s[i][p - 1], s[i + (1 << (p - 1))][p - 1]);
            }
        }
    }

    T query(int l, int r, int k = 0){
        int k = lg[r - l + 1];

        return min(s[l][k], s[r - (1 << k) + 1][k]);
    }
};

void solve(){
    int n; cin >> n;

    int a[n];
    for(int& e: a) cin >> e;

    vector <int> b(n);
    for(int& e: b) cin >> e;

    int m; cin >> m;

    map <int, int> x;
    for(int i = 0; i < m; ++i){
        int e; cin >> e; ++x[e];
    }

    for(int  i = 0; i < n; ++i){
        if (b[i] > a[i]){
            cout << "NO\n"; return;
        }
    }

    map <int, pair <int, int>> f;
    sparse <int> t(b);

    for(int i = 0; i < n; ++i){
        if (a[i] == b[i]) continue;

        if (f.count(b[i])){
            auto& [cnt, j] = f[b[i]];

            if (t.query(j,i) > b[i]) ++cnt; 
            j = i;
        }

        else f[b[i]] = {1, i};  
    }

    for(auto it = x.rbegin(); it != x.rend(); ++it){
        auto [k, v] = *it;

        if (not f.count(k)) continue;

        if (f[k].first > v){
            cout << "NO\n"; return;
        }

        else f.erase(k);
    }

    f.empty() ? cout << "YES\n" : cout << "NO\n";
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin >> t;
    while(t--) solve();
}