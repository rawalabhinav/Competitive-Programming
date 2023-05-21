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

void solve(){
    int n; cin >> n;

    moset s;
    for(int i = 1; i <= n; ++i) s.insert(i);

    int shift = 0;
    while(!s.empty()){
        shift = (shift + 1) % (s.size());
        auto head = s.find_by_order(shift);

        cout << *head << " ";
        s.erase(head);
    }
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
}   