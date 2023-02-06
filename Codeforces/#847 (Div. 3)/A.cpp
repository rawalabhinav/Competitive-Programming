#include <bits/stdc++.h>
using namespace std;

#ifdef RAWAL
    #include <Collections/debug.h>
#endif

#define int long long int

string pi = "314159265358979323846264338327";

void solve(){
    string s; cin >> s;

    for(int i = 0;i < s.length() + 1; ++i){
        if(s[i] != pi[i]){
            cout << i << '\n'; return;
        }
    }
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin >> t;
    while(t--) solve();
}