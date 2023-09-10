#include <bits/stdc++.h>
using namespace std;

#ifdef RAWAL
    #include <Collections/debug.h>
#endif

#define int long long int
const string pi = "3.1415926535897932384626433832795028841971693993751058209749445923078164062862089986280348253421170679";

void solve(){
    int n; cin >> n;
    cout << pi.substr(0, n + 2);
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
}