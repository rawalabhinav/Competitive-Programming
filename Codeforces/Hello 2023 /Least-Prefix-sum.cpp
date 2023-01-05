#include <bits/stdc++.h>
using namespace std;

#ifdef RAWAL
    #include <Collections/debug.h>
#endif

#define int long long int

void solve(){
    int n, m; cin >> n >> m;

    int a[n]; 
    for(int& e: a) cin >> e;

    // int p[n + 1]; p[0] = 0;
    // for(int i = 1; i < m + 1; ++i){
    //     p[i] = p[i - 1] + a[i - 1];


    // }

    // First find prefix till p[m] only
    // Bas 1 -> m tak jao, check if its even needed or not (matlab pos vala case)
    // fer ulta chalo, if p[i] < p[m] (i < m) then flip the lowest ele (max  negative)
    // in the range 1 to i (both incl), add 2 * x to p[m]
    // aisa krte jao i = 1 tak

    // fer m + 1 ke baad prefix lete jao
    // agar ab p[i] < p[m] hua toh m + 1 se i tak max neg ele ko
    // flip kardo and p[]

}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin >> t;
    while(t--) solve();
}