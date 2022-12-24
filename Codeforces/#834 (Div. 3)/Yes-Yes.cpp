#include <bits/stdc++.h>
using namespace std;

#ifdef RAWAL 
    #include <Collections/debug.h>
#endif

#define int long long int
  
string solve(){
    string s, p = "Yes"; cin >> s;
    
    map <char, int> m{{'Y', 0}, {'e', 1}, {'s', 2}};
    
    for(int i = 0, j = m[s[0]]; i < s.length(); ++i, ++j){
        if (s[i] != p[j % 3]) return "NO\n";
    } return "YES\n"; 
}

signed main(){
    ios_base::sync_with_stdio(false); 
    cin.tie(nullptr);
    
    int t; cin >> t;
    while(t--)  cout << solve();
}