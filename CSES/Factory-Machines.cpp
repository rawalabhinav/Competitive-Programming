#include <iostream>
#define int long long int

void solve(){
    int n, p; std::cin >> n >> p;

    int t[n];
    for(int& e: t) std::cin >> e;

    auto products = [&](int m, int tot = 0){
        for(int& e: t) tot += m / e;
        return tot < p;
    };

    int l = 0, h = p * (*std::min_element(t, t + n));
    for(int m = (l + h) >> 1; l < h; m = (l + h) >> 1){
        if (products(m)) l = m + 1;
        else h = m;
    } std::cout << l;
}

signed main(){
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    solve();
}