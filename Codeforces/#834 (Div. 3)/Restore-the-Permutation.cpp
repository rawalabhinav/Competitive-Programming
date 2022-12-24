#include <bits/stdc++.h>
using namespace std;

#ifdef RAWAL 
    #include <Collections/debug.h>
#endif

#define int long long int

int p2[15], p5[15];
void precompile(){
    
    p2[0] = 1, p5[0] = 1;
    for(int i = 1; i < 15; ++i){
        
        p2[i] = 2 * p2[i - 1];
        p5[i] = 5 * p5[i - 1];
    }
}
void __attribute__((constructor)) precompile();

void solve(){
    int n, m; cin >> n >> m;
    
    int tn = 0, fn = 0, p = 0, ans = n;
    
    tn = __builtin_ctzll(n);
    for(int i = n; !(i % 5); i /= 5) ++fn;
        
    for(int tm = 0; tm < 15; ++tm){
        for(int fm = 0; fm < 15; ++fm){
            
            if (p2[tm] * p5[fm] > m) continue;
            

            if (min(tm + tn, fm + fn) < p) continue;
            int k = p2[tm] * p5[fm];
            
            if (min(tm + tn, fm + fn) > p){
                
                p = min(tm + tn, fm + fn);
                ans = n * (m / k) * k;
            } 
            
            else if (n * (m / k) * k > ans){
                ans = n * (m / k) * k;
            }
            
        }
    } cout << ans << '\n';
    
}

signed main(){
    ios_base::sync_with_stdio(false); 
    cin.tie(nullptr);
    
    int t; cin >> t;
    while(t--)  solve();
}