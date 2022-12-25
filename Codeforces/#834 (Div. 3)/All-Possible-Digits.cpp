#include <bits/stdc++.h>
using namespace std;

#ifdef RAWAL
    #include <Collections/debug.h>
#endif

#define int long long int

int solve(){
    int n, p; cin >> n >> p;
    
    int a[n];
    for(int& e: a) cin >> e;
    
    set <int> s(a, a + n);

    if (!a[n - 1]){
        for(int i = p - 1; i > 0; --i){
            if (!s.count(i)) return i;
        } return 0;
    }

    if (n < 2) return p - 1 - (a[0] == 2);
    int j = n - 2, put = 0;
    

    for(int i = n - 2; i > -1; --i, --j){   
        if (a[i] == p - 1) continue;

        if (a[i] + 1 < a[n - 1]){
            put += (!s.count(a[i] + 1)); 
            
            s.insert(a[i] + 1); 
        } break;
    }

    if (j < 0){
        put += (!s.count(1)); s.insert(1); 
    }   
    
    for(int i = a[n - 1] - 1; i > -1; --i){
        if (!s.count(i)) return p - a[n - 1] + i;
    }

    if (put) return p - a[n - 1];

    for(int i = p - 1; i > a[n - 1]; --i){
        if (!s.count(i)) return i - a[n - 1];
    } return 0;
}

signed main(){
    ios_base::sync_with_stdio(false); 
    cin.tie(nullptr);
    
    int t; cin >> t;
    while(t--) cout << solve() << '\n';
}
