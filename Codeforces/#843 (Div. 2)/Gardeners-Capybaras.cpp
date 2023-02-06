#include <bits/stdc++.h>
using namespace std;

#ifdef RAWAL
    #include <Collections/debug.h>
#endif

#define int long long int

void solve(){
    string s; cin >> s; int n = s.length();

    if (s[0] == 'a') cout << s.substr(0, n - 2) << ' ' << s[n - 2] << ' ' << s[n - 1] << '\n';
    else  cout << s[0] << ' ' << s[1] << ' ' << s.substr(2, n - 2) << '\n';
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin >> t;
    while(t--) solve();
}