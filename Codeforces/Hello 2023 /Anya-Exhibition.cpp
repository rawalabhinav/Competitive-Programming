#include <bits/stdc++.h>
using namespace std;

struct bit{
    unsigned int value: 1;
};

void solve(){
    bit num; num.value = 1;
    cout << num.value;
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin >> t;
    while(t--) solve();
}