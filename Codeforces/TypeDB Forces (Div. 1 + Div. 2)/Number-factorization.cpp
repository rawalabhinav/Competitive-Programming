#include <bits/stdc++.h>
using namespace std;

#ifdef RAWAL
    #include <Collections/debug.h>
#endif

#define int long long int

void solve(){
    int n, product = 1; cin >> n;

    vector <pair <int, int>> p;
    int f = __builtin_ctzll(n);

    if (f){
        p.push_back({f, 2ll});  
        n /= (1 << f); ++product; f = 0;
    }

    for(int i = 3; i * i <= n; i += 2, f = 0){
        for(; n % i == 0; n /= i) ++f;

        if (f){
            p.push_back({f, i});  
            product *= i;
        }
    }

    if (n > 2){
        p.push_back({1ll, n}); product *= n;
    }

    sort(p.begin(), p.end());
    int sum = 0, i = 1; f = 0;

    p.push_back({1000, 1});
    while(i < p.size()){
        if (p[i].first > p[i - 1].first){
            sum += product * (p[i - 1].first - f);
            f = p[i - 1].first;

            for(int j = i - 1; p[j].first == f; --j){
                product /= p[j].second;
            }
        } ++i;
    }

    cout << sum << '\n';
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin >> t;
    while(t--) solve();
}