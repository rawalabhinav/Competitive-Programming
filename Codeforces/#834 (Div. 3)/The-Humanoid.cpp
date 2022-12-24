#include <bits/stdc++.h>
using namespace std;

#ifdef RAWAL 
    #include <Collections/debug.h>
#endif

#define int long long int

void solve(){
    int n, h; cin >> n >> h;
    
    int a[n];
    for(int& e: a) cin >> e;
    	
    sort(a, a + n);
	vector <int> p[3] = {{2, 2, 3}, {2, 3, 2}, {3, 2, 2}};
	
	int ans = 0;
	for(auto& v: p){
		int i, health = h;
		
		for(i = 0; i < n; ++i){
			if (health > a[i]) 	   health += a[i] / 2;
			
			else if (v.size()){
				health *= v.back(); v.pop_back(); --i;
			}
			
			else break;
		}
		ans = max(ans, i);
	} cout << ans << '\n';
}

signed main(){
    ios_base::sync_with_stdio(false); 
    cin.tie(nullptr);
    
    int t; cin >> t;
    while(t--) solve();
}
