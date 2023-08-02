#include <bits/stdc++.h>
using namespace std;

#ifdef RAWAL
    #include <Collections/debug.h>
#endif

#define int long long int

int n, m;
vector <vector <int>> vis;
vector <string> s;

int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};

void dfs(int i, int j){
    if (i < 0 or i >= n or j < 0 or j >= m) return;
    
    if (s[i][j] != '.' or vis[i][j]) return;
    vis[i][j] = 1;

    for(int k = 0; k < 4; ++k){
        dfs(i + dx[k], j + dy[k]);
    }
}

void solve(){
    int ans = 0; cin >> n >> m;

    s.resize(n);
    vis.resize(n, vector <int>(m));
    
    for(auto& e: s) cin >> e;

    for(int i = 0; i < n; ++i){
        for(int j = 0; j < m; ++j){
            if (s[i][j] != '.' or vis[i][j]) continue;

            ++ans;
            dfs(i, j);
        }
    }

    cout << ans;
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
}