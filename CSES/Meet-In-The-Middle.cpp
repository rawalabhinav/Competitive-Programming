#include <bits/stdc++.h>
using namespace std;

#ifdef RAWAL
#include <Collections/debug.h>
#endif

#define int long long int

struct custom_hash {
    static uint64_t splitmix64(uint64_t x) {
        // http://xorshift.di.unimi.it/splitmix64.c
        x += 0x9e3779b97f4a7c15;
        x = (x ^(x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }

    size_t operator()(uint64_t x) const {
        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x + FIXED_RANDOM);
    }
};

void solve() {
    int n, x; cin >> n >> x;

    int ans = 0;
    int a[n];
    unordered_map <int, int, custom_hash> left;

    for (int& e : a) cin >> e;
    
    auto process_segment = [&](int l, int r, function <void(int)> process) {
        int m = r - l + 1;

        for (int i = 0; i < (1 << m); ++i) {
            int sum = 0;

            for (int j = 0, k = i; k > 0; k >>= 1, ++j) {
                if (k & 1) sum += a[l + j];
            }

            process(sum);
        }
    };

    process_segment(0, n / 2 - 1, [&](int sum){
        ++left[sum];
    });
    process_segment(n / 2, n - 1, [&](int sum){
        if (left.count(x - sum)) ans += left[x - sum];
    });

    cout << ans;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
}
