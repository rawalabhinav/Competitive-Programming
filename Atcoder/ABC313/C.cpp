#include <bits/stdc++.h>
using namespace std;

#ifdef RAWAL
    #include <Collections/debug.h>
#endif

#define int long long int

void solve(){
    int n; cin >> n;

    int a[n], sum = 0, smol = 0, big = 0;
    for(int& e: a){
        cin >> e; sum += e;
    }

    sum /= n;
    for(int& e: a) {
        if (e <= sum) smol += sum - e;
        else big += e - (sum + 1);
    }

    cout << max(smol, big);
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
}