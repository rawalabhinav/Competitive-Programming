#include <bits/stdc++.h>
using namespace std;

#ifdef RAWAL
    #include <Collections/debug.h>
#endif

#define int long long int

void solve(){
    int n; cin >> n;

    vector <vector <int>> s(n, vector <int>(3));
    vector <vector <int>> e(n, vector <int>(3));
    int o[n], m[n];

    iota(o, o + n, 1ll);
    multiset <int> free(o, o + n);
    
    for(int i = 0; i < n; ++i){
        cin >> s[i][0] >> e[i][0];
        s[i][1] = e[i][0], e[i][1] = s[i][0];
        s[i][2] = i, e[i][2] = i;
    }

    sort(s.begin(), s.end()); 
    sort(e.begin(), e.end()); 
    
    int overlap = 0, i = 0, j = 0, k = 0;
    while(i < n && j < n){
        if (s[i][0] <= e[j][0]){
            o[s[i][2]] = (*free.begin());
            m[s[i][2]] = o[s[i][2]];

            ++overlap; ++i;
            free.erase(free.begin());
        } else {
            free.insert(m[e[j][2]]);
            --overlap; ++j;
        }

        k = max(k, overlap);
    }

    cout << k << "\n";
    for(int& e: o) cout << e << ' ';

}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
}