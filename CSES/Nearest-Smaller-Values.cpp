#include <bits/stdc++.h>
using namespace std;

#ifdef RAWAL
    #include <Collections/debug.h>
#endif

#define int long long int

void solve(){
    int n; cin >> n;

    int a[n];
    for(int& e: a) cin >> e;

    stack <int> s;

    for(int i = 0; i < n; ++i){
        for(; !s.empty() && a[i] <= a[s.top()]; s.pop());
        s.empty() ? cout << "0 " : cout << s.top() + 1 << ' ';
        s.push(i); 
    }
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
}