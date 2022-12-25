#include <bits/stdc++.h>
using namespace std;

#ifdef RAWAL 
    #include <Collections/debug.h>
#endif

#define int long long int
  
int solve(){
    int l, r, x, a, b; cin >> l >> r >> x >> a >> b;
    
    if (a == b) return 0;
    if (b > a) swap(a, b);
    

	if (a - b >= x) return 1;
	
	if (b - x >= l or a + x <= r) return 2;
	if (r - b >= x and a - l >= x) return 3;
    
	return -1;
}

signed main(){
    ios_base::sync_with_stdio(false); 
    cin.tie(nullptr);
    
    int t; cin >> t;
    while(t--) cout << solve() << '\n';
}
