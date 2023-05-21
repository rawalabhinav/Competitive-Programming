#include <bits/stdc++.h>
using namespace std;

#ifdef RAWAL
    #include <Collections/debug.h>
#endif

#define int long long int

void solve(){
    int n, x; cin >> n >> x;

    int a[n];
    map <int, vector <int>> m;

    for(int i = 0; i < n; ++i){
        cin >> a[i]; m[a[i]].emplace_back(i);
    }

    for(int i = 0; i < n; ++i){
        for(int j = i + 1; j < n; ++j){
            int k = x - a[i] - a[j];
            if (!m.count(k)) continue;
            
            for(int e: m[k]){
                if (e != i and e != j){
                    cout << i + 1 << " " << j + 1 << " " << e + 1;
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