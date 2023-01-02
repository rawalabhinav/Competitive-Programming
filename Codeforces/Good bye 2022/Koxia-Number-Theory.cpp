#include <bits/stdc++.h>
using namespace std;

#ifdef RAWAL
    #include <Collections/debug.h>
#endif

#define int long long int
int p[] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31,
           37, 41, 43, 47, 53, 59, 61, 67, 71, 73,
           79, 83, 89, 97, 101};

void solve(){
    int n; cin >> n;

    int a[n]; 
    for(int& e: a) cin >> e; 
    
    map <int, int> m;   
    for(int& e: a){
        if (m[e]++){
            cout << "NO\n"; return;
        }
    }

    for(auto& e: p){
        int f[e]{0};

        for(int j = 0; j < n; ++j) ++f[a[j] % e];

        if (*min_element(f, f + e) > 1){
            cout << "NO\n"; return;
        }
    } cout << "YES\n";
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin >> t;
    while(t--) solve();
}