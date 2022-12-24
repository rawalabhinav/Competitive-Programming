#include <bits/stdc++.h>
using namespace std;

#ifdef RAWAL 
    #include <Collections/debug.h>
#endif

#define int long long int

set <int> square;
void precompile(){
	for(int i = 1; i < 1000; ++i){
<<<<<<< HEAD
		square.insert(i * i);
	}
=======
        square.insert(i * i);
    }
>>>>>>> da41d33 (Complete)
}

void __attribute__((constructor)) precompile();

string solve(){
    int m, s, b; cin >> m >> s;
    
    int sum = 0, n = 0;
    for(int i = 0; i < m; ++i){
    	
    	cin >> b; sum += b;
    	n = max(b, n);
    }
    
    auto it = square.find(1 + 8 * (s + sum));
    if (it == square.end()) return "NO\n";
    
    if (*it < (2 * n + 1) * (2 * n + 1)) return "NO\n";
    return "YES\n"; 
}

signed main(){
    ios_base::sync_with_stdio(false); 
    cin.tie(nullptr);
    
    int t; cin >> t;
    while(t--)  cout << solve();
}
