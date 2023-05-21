#include <bits/stdc++.h>
using namespace std;

#ifdef RAWAL
    #include <Collections/debug.h>
#endif

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
  
#define moset tree <int, null_type,less_equal <int>, rb_tree_tag, tree_order_statistics_node_update>
#define int long long int

void solve() {
    int n; cin >> n;

    vector <vector <int>> a(n, vector <int>(3));
    int ans[n];

    moset in, out;

    for (int i = 0; i < n; ++i) {
        cin >> a[i][0] >> a[i][1];

        in.insert(a[i][1]);
        a[i][1] = -a[i][1], a[i][2] = i;
    }

    sort(a.begin(), a.end());
    int order;

    for (auto &v: a) {
        order = in.order_of_key(1 - v[1]);
        in.erase(in.find_by_order(order - 1));

        ans[v[2]] = order - 1;
    }

    for(int& e: ans) cout << bool(e) << ' ';
    cout << '\n';

    for (auto& v: a) {
        ans[v[2]] = (int)out.size() - out.order_of_key(-v[1]);
        out.insert(-v[1]);
    }

    for(int& e: ans) cout << bool(e) << ' ';
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    solve();
}