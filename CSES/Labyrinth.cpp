#include <bits/stdc++.h>
using namespace std;

#ifdef RAWAL
    #include <Collections/debug.h>
#endif

#define int long long int

int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};
string dir = "RDLU";

void solve(){
    int n, m; cin >> n >> m;

    vector <string> s(n);
    vector <vector <int>> vis(n, vector <int>(m));
    
    for(auto& e: s) cin >> e;

    auto bfs = [&](int x, int y){
        queue <tuple <int, int, int>> q;
        q.push({x, y, 0});

        while(!q.empty()){
            auto [i, j, c] = q.front();
            q.pop();

            if (i < 0 or i >= n or j < 0 or j >= m or s[i][j] == '#' or vis[i][j]) continue;
            vis[i][j] = c;

            if (s[i][j] == 'B'){
                stack <char> st;
                int len = 0;

                while(s[i][j] != 'A'){
                    c = vis[i][j] - 1;
                    st.push(dir[c]);
                    ++len;
                    i -= dx[c], j -= dy[c];
                }

                cout << "YES\n" << len << '\n';
                while(!st.empty()){
                    cout << st.top(); st.pop();
                }

                return;
            }

            for(int k = 0; k < 4; ++k){
                q.push({i + dx[k], j + dy[k], k + 1});
            }
        }

        cout << "NO";
    };

    for(int i = 0; i < n; ++i){
        for(int j = 0; j < m; ++j){
            if (s[i][j] == 'A'){
                bfs(i, j); exit(0);
            }
        }
    }

    cout << "NO";

}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
}