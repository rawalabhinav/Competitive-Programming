#include <bits/stdc++.h>
using namespace std;

#ifdef RAWAL
    #include <Collections/debug.h>
#endif

constexpr int mod = 1e9 + 7;

void solve(){
    int n, m; cin >> n >> m;

    if (n % 2 && m % 2){
        cout << "0"; return;
    }

    vector <vector <vector <int>>> memo(m, vector <vector <int>>(n, vector <int>(2 * (1 << n))));
    
    function <int(int, int, int)> f = [&](int i, int j, int mask){
        if (i == m) return 1;
        if (j == n) return f(i + 1, 0, mask); 

        if (memo[i][j][mask]) return memo[i][j][mask];

        int a = 0, b = 0, c = 0;
        if ((mask & (1 << j))){
            a = f(i, j + 1, mask ^ (1 << j));
        } else {
            if (i != m - 1) b = f(i, j + 1, mask ^ (1 << j));

            if (j != n - 1 && (mask & (1 << (j + 1))) == 0) c = f(i, j + 2, mask);
        }

        return memo[i][j][mask] = long(a + b + c) % mod;
    };

    cout << f(0, 0, (1 << n));
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
}