#include <bits/stdc++.h>
using namespace std;

#ifdef RAWAL 
    #include <Collections/debug.h>
#endif

#define int long long int
  
void solve(){
    int n; cin >> n;
    
    int v[n]; iota(v, v + n, -n);
    set <int> s(v, v + n), f;
    
    int a[n], b[n / 2];
    int has = 0;
    
    for(int i = 0; i < n / 2; ++i){
    	cin >> b[i]; 
    	
    	a[2 * i + 1] = b[i];
    	s.erase(-b[i]); 
    	
    	if (f.count(b[i])) has = 1;
		else f.insert(b[i]);
    }
    
    if (has){
    	cout << "-1\n"; return;
	}
    
    for(int i = n / 2 - 1; i > -1; --i){
    	auto it = s.upper_bound(-b[i]);
    	
    
    	if (it == s.end() or abs(*it) > b[i]){
    		cout << "-1\n"; return;
    	}
    	
    	a[2 * i] = abs(*it);
    	s.erase(*it);
    	
    }
    
    for(int& e: a) cout << e << ' ';
	cout << '\n';   
}

signed main(){
    ios_base::sync_with_stdio(false); 
    cin.tie(nullptr);
    
    int t; cin >> t;
    while(t--)  solve();
}