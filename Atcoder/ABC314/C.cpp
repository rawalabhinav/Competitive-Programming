#include <bits/stdc++.h>
using namespace std;

#ifdef RAWAL
    #include <Collections/debug.h>
#endif

#define int long long int

void solve(){
    int n, m; string s; 
    cin >> n >> m >> s;

    vector <int> ind[n + 1];
    for(int c, i = 0; i < n; ++i){
        cin >> c;

        ind[c].emplace_back(i);
    }

    for(int i = 1; i <= n; ++i){
        if (!ind[i].size()) continue;

        char prev = s[ind[i].back()];
        for(int& e: ind[i]) swap(s[e], prev);
    }

    cout << s;
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
}