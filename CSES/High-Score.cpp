#include <bits/stdc++.h>
using namespace std;

#ifdef RAWAL
    #include <Collections/debug.h>
#endif

#define int long long int
const int INF = 1000000000;

int n, m;
vector <vector <pair <int, int>>> adj;
vector <int> d;

bool spfa(int s) {
    d.assign(n, INF);
    vector <int> cnt(n, 0);
    vector <bool> inqueue(n, false);
    queue <int> q;

    d[s] = 0;
    q.push(s);
    inqueue[s] = true;
    while (!q.empty()) {
        int v = q.front();
        q.pop();
        inqueue[v] = false;

        for (auto edge : adj[v]) {
            int to = edge.first;
            int len = edge.second;

            if (d[v] + len < d[to]) {
                d[to] = d[v] + len;

                if (!inqueue[to]) {
                    q.push(to);
                    inqueue[to] = true;
                    cnt[to]++;
                    if (cnt[to] > n)return false;  // negative cycle
                }
            }
        }
    }
    return true;
}

void solve(){
    cin >> n >> m;

    int u, v, x;
    adj.resize(n);

    for(int i = 0; i < m; ++i){
        cin >> u >> v >>  x;

        adj[u - 1].push_back({v - 1, -x});
    }
    
    if (spfa(0)){
        cout << -d[n - 1];
    } else {
        cout << "-1";
    }
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
}