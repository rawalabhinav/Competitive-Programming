#include <bits/stdc++.h>
using namespace std;

#ifdef RAWAL
    #include <Collections/debug.h>
#endif

#define int long long int

void solve(){
    int n, k; cin >> n >> k;

    int a[n];
    for(int& e: a) cin >> e;

    if (k < 2){
        while(n--) cout << "0 ";
        return;
    }

    multiset <int> l, r(a, a + k / 2);
    for(int i = k / 2; i < k; ++i){
        if (a[i] <= *r.begin()){
            l.insert(a[i]);
        } else {
            r.insert(a[i]);
            l.insert(*r.begin());
            r.erase(r.begin());
        }
    }

    int suml = accumulate(l.begin(), l.end(), 0ll);
    int sumr = accumulate(r.begin(), r.end(), 0ll);

    for(int i = k; i <= n; ++i){
        cout << sumr - suml + (*l.rbegin()) * (k & 1) << ' ';

        if (i == n) break;

        if (l.find(a[i - k]) != l.end()){
            l.erase(l.find(a[i - k]));
            l.insert(a[i]);
            suml += a[i] - a[i - k];
        } else {
            r.erase(r.find(a[i - k]));
            r.insert(a[i]);
            sumr += a[i] - a[i - k];
        }

        if (*l.rbegin() > *r.begin()){
            sumr += *l.rbegin() - *r.begin();
            suml -= *l.rbegin() - *r.begin();

            int tmpr = *r.begin(), tmpl = *l.rbegin();

            l.erase(l.find(tmpl)); l.insert(tmpr);
            r.erase(r.begin()); r.insert(tmpl);
        }
    }
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
}