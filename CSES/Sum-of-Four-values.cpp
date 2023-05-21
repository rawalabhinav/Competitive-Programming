#include <bits/stdc++.h>
using namespace std;

#ifdef RAWAL
    #include <Collections/debug.h>
#endif

#define int long long int

void solve(){
    int n, x; cin >> n >> x;

    int a[n];
    for(int& e: a) cin >> e;
    
    map <int, vector <pair<int, int>>> m;
    for(int i = 0; i < n; ++i){
        for(int j = i + 1; j < n; ++j){
            m[a[i] + a[j]].push_back({i, j});
        }
    }
    
    for(int i = 0; i < n; ++i){
        for(int j = i + 1; j < n; ++j){
            int k = x - a[i] - a[j];
            if (!m.count(k)) continue;
            
            for(auto [x, y]: m[k]){
                if (x != i and x != j and y != i and y != j){
                    cout << i + 1 << " " << j + 1 << " " << x + 1 << " " << y + 1;
                    return;
                }
            }
        
        }
    }

    cout << "IMPOSSIBLE";
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
}