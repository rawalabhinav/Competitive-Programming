#include <bits/stdc++.h>
using namespace std;

#ifdef RAWAL
    #include <Collections/debug.h>
#endif

#define int long long int

void solve(){
    int n, k; cin >> n >> k;

    int a[n];
    for(int& e: a) cin >> e;

    multiset <int> m(a, a + k);
    set <int> s(a, a + k);

    int i = 0, j = k, sum = n * k - (k * k - k) / 2;
    for(; j < n; m.insert(a[(j++)])){
        if (s.find(a[j]) != s.end()) continue;

        for(; s.size() == k; ++i){
            m.erase(m.find(a[i]));
            
            sum += j - i - k;
            if (m.find(a[i]) == m.end()) s.erase(a[i]);
        } s.insert(a[j]);
    }
    
    for(; n - i >= k; ++i) sum += n - i - k;
    cout << sum ;
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
}