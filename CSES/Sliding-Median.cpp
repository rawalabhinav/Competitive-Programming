#include <bits/stdc++.h>
using namespace std;

#ifdef RAWAL
    #include <Collections/debug.h>
#endif

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
  
#define moset tree <int, null_type, less_equal <int>, rb_tree_tag, tree_order_statistics_node_update>
#define int long long int

void solve(){
    int n, k; cin >> n >> k;

    int a[n];
    for(int& e: a) cin >> e;

    moset m(a, a + k);
    int mid = (k + 1) / 2 - 1;
    for(int i = k; i < n; ++i){
        cout << *m.find_by_order(mid) << ' ';

        m.erase(m.find_by_order(m.order_of_key(a[i - k])));


        m.insert(a[i]);
    } cout << *m.find_by_order(mid) << ' ';
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
}