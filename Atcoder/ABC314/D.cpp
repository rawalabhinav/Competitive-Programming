#include <bits/stdc++.h>
using namespace std;

#ifdef RAWAL
    #include <Collections/debug.h>
#endif

#define int long long int

void solve(){
    int n, q; string s;
    cin >> n >> s >> q;

    vector <int> change(q);
    int last = 0, low = -1, up = -1;

    for(int t, x, i = 0; i < q; ++i){
        char c; cin >> t >> x >> c;

        if (t == 1) {
            change[i] = x - 1; s[x - 1] = c;
        } else if (t == 2){
            low = i, last = 2;
        } else {
            up = i, last = 3;
        }
    }
    
    int prev = q, ind = -1;
    int vis[n]{0};

    ind = (last == 3) ? up : low;
    if (ind < 0) {
        cout << s; return;
    }

    auto lowercase = [&](char& c){
        if (c - 'A' < 26) c = 'a' + (c - 'A');
    };

    auto uppercase = [&](char& c){
        if (c - 'A' > 26) c = 'A' + (c - 'a');
    };


    for(int i = q - 1; i > -1; --i){
        if (change[i] && ind < i){
            vis[change[i]] = 1; continue;
        }

        if (!change[i] or vis[change[i]]){
            continue;
        }

        (last == 3) ? uppercase(s[change[i]]) : lowercase(s[change[i]]);
        vis[change[i]] = 1;
    }

    for(int i = 0; i < n; ++i){
        if (vis[i]) continue;
        
        (last == 3) ? uppercase(s[i]) : lowercase(s[i]);
    }
    cout << s;
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
}