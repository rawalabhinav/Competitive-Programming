#include <bits/stdc++.h>
using namespace std;

#ifdef RAWAL
    #include <Collections/debug.h>
#endif

#define int long long int

void solve(){
    int n, m, ans = 1; cin >> n >> m;

    int a[n + 2]{0}, ind[n + 2]{0};
    a[n + 2] = n + 1, ind[n + 2] = n + 1;

    for(int i = 1 ; i <= n; ++i){
        cin >> a[i]; ind[a[i]] = i;
    }

    for (int i = 2; i <= n; ++i){
        ans += (ind[i] < ind[i - 1]);
    }


    for(int i, j; m; --m){
        cin >> i >> j;

        if (abs(a[i] - a[j]) != 1){
            if (ind[a[i]] < ind[a[i] + 1]){
                ans += (ind[a[j]] > ind[a[i] + 1]);
            } else {
                ans -= (ind[a[j]] < ind[a[i] + 1]);
            }
            
            if (ind[a[i]] > ind[a[i] - 1]){
                ans += (ind[a[j]] < ind[a[i] - 1]);
            } else {
                ans -= (ind[a[j]] > ind[a[i] - 1]);
            }

            if (ind[a[j]] < ind[a[j] + 1]){
                ans += (ind[a[i]] > ind[a[j] + 1]);
            } else {
                ans -= (ind[a[i]] < ind[a[j] + 1]);
            }
            
            if (ind[a[j]] > ind[a[j] - 1]){
                ans += (ind[a[i]] < ind[a[j] - 1]);
            } else {
                ans -= (ind[a[i]] > ind[a[j] - 1]);
            }
        } else if (a[i] > a[j]){
            if (ind[a[i]] < ind[a[i] + 1]){
                ans += (ind[a[j]] > ind[a[i] + 1]);
            } else {
                ans -= (ind[a[j]] < ind[a[i] + 1]);
            }

            if (ind[a[j]] > ind[a[j] - 1]){
                ans += (ind[a[i]] < ind[a[j] - 1]);
            } else {
                ans -= (ind[a[i]] > ind[a[j] - 1]);
            }

            if (ind[a[i]] > ind[a[j]]) ++ans;
            else --ans;
                
        } else {
            if (ind[a[j]] < ind[a[j] + 1]){
                ans += (ind[a[i]] > ind[a[j] + 1]);
            } else {
                ans -= (ind[a[i]] < ind[a[j] + 1]);
            }

            if (ind[a[i]] > ind[a[i] - 1]){
                ans += (ind[a[j]] < ind[a[i] - 1]);
            } else {
                ans -= (ind[a[j]] > ind[a[i] - 1]);
            } 

            if (ind[a[i]] < ind[a[j]]) ++ans;
            else --ans;
        }

        swap(ind[a[i]], ind[a[j]]);
        swap(a[i], a[j]);

        cout << ans << '\n';
    }
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
}