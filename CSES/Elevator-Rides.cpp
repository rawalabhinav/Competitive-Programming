#include <bits/stdc++.h>
using namespace std;

#ifdef RAWAL
    #include <Collections/debug.h>
#endif

void solve(){
    int n, x; cin >> n >> x;
    int weight[n];

    array <int, 2> best[1 << n];
    for(int& e: weight) cin >> e;

    best[0] = {1, 0};
    for (int s = 1; s < (1 << n); s++) {
        best[s] = {n, 0};

        for (int p = 0; p < n; ++p) {
            if (s & (1 << p)) {
                auto [rides, small] = best[s ^ (1 << p)];

                // add p to an the smallest weighted ride
                // or reserve a new ride for p
                if (small + weight[p] <= x) {
                    small += weight[p];
                } else {
                    ++rides;
                    small = weight[p];
                }

                best[s] = min(best[s], {rides, small});
            }
        }
    }

    cout << best[(1 << n) - 1][0];

}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
}