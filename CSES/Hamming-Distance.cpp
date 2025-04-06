#include <bits/stdc++.h>
using namespace std;

#ifdef RAWAL
    #include <Collections/debug.h>
#endif

int bin_to_decimal(string& s) {
    int k = s.length();
    int number = 0;

    for (int i = 1; i <= k; ++i) {
        if (s[i - 1] == '1') number += (1 << (k - i));
    }

    return number;
}

inline int hamming(int a, int b) {
    return __builtin_popcount(a ^ b);
}

void solve(){
    int n, k; cin >> n >> k;
    int ans = k;

    vector <int> codes(n);
    
    for (int i = 0; i < n; ++i) {
        string s; cin >> s;
        codes[i] = bin_to_decimal(s);
    }

    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            ans = min(ans, hamming(codes[i], codes[j]));
        }
    }

    cout << ans;
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
}