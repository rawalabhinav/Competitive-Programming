#include <bits/stdc++.h>
using namespace std;

#ifdef RAWAL
    #include <Collections/debug.h>
#endif

#define int long long int

int n, m, r, c; 
deque <char> path;
vector <string> g;
vector <vector <int>> d, vis;

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
string dir = "DRUL";

void dfs(int i, int j, int s = 0){
    if (i >= n or j >= m or i < 0 or j < 0 
        or g[i][j] == '#' or d[i][j] <= s) return;

    if (!i or !j or i == n - 1 or j == m - 1){
        cout << "YES\n" << s << '\n';
        while(!path.empty()){
            cout << path.front();
            path.pop_front();
        } exit(0);
    }

    if (vis[i][j]) return;
    vis[i][j] = 1;

    for(int k = 0; k < 4; ++k){
        path.push_back(dir[k]);
        dfs(i + dx[k], j + dy[k], s + 1);
        path.pop_back();
    }
}

void solve(){
    cin >> n >> m;

    g.resize(n);
    for(string& s: g) cin >> s;

    queue <tuple <int, int, int>> q;
    d.resize(n, vector <int>(m, 1e9));
    vis.resize(n, vector <int>(m));
    
    for(int i = 0; i < n; ++i){
        for(int j = 0; j < m; ++j){
            if (g[i][j] == 'M') q.push({i, j, 0});
            else if (g[i][j] == 'A') r = i, c = j;
        }
    }

    while(!q.empty()){
        auto [i, j, s] = q.front();
        q.pop();

        if (i >= n or j >= m or i < 0 or j < 0 
            or g[i][j] == '#' or d[i][j] <= s) continue;
        d[i][j] = s;
 
        for(int k = 0; k < 4; ++k){
            q.push({i + dx[k], j + dy[k], s + 1});
        }
    }
    
    dfs(r, c); 
    cout << "NO\n";
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
}