#include <bits/stdc++.h>
using namespace std;

#ifdef RAWAL
    #include <Collections/debug.h>
#endif

#define int long long int

void solve(){
    int n; cin >> n;

    int sum = 0, mus = 0, c = 0, d = 0;
    for(int a = 0, b = 0; a < n; a += 2 * b + 1, b += 2){
        
        if (b % 4 == 0){
            if (2 * b + 1 > n - a) {
                sum += n - a; c += (n - a) / 2;
            } else {
                sum += 2 * b + 1; c += b;
            }
        } else{
            if (2 * b + 1 > n - a) {
                mus += n - a; d += (n - a + 1) / 2;
            } else {
                mus += 2 * b + 1; d += b + 1;
            }            
        }

    } 

    cout << sum - c << ' ' << c << ' ';
    cout << mus - d << ' ' << d << '\n';

}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin >> t;
    while(t--) solve();
}