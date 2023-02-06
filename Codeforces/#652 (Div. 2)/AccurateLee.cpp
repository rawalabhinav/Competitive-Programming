#include <bits/stdc++.h>
using namespace std;

void solve(){
    int n, i, j; string s; cin >> n >> s;
    
    for(i = 0; i < n && s[i] != '1'; ++i);
    for(j = n - 1; j > -1 && s[j] != '0'; --j);

    if (j < i){
        cout << s << '\n'; return;
    } cout << string(i, '0') + "0" + string(n - j - 1, '1') << '\n';
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin >> t;
    while(t--) solve();
}