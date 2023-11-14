#include <bits/stdc++.h>
using namespace std;

#ifdef RAWAL
    #include <Collections/debug.h>
#endif

#define int long long int
vector <array <int, 12>> memo;

int f(string& s, int i, int d){
    if (i == s.length()) return 1;

    if (memo[i][d]) return memo[i][d];
    int sum = 0;

    if (i == 0){
        for(int j = 1; j < s[0] - '0'; ++j){
            sum += f(s, 1, j);
        }

        for(int j = 1; j <= s.length() ; ++j){
            if (j > 1 && s[j - 1] == s[j - 2]) break;

            sum += f(s, j, 10); 
        }

        sum += f(s, 1, 11);
    }

    else if (d == 10){
        for(int j = 0; j < s[i] - '0'; ++j){
            if (j != s[i - 1] - '0') sum += f(s, i + 1, j);
        }
    }

    else {
        for(int j = (d == 11); j < 10; ++j){
            sum += f(s, i + 1, j);
        }

        if (d == 11) sum += f(s, i + 1, 11);
        else sum -= f(s, i + 1, d); 
    }

    return memo[i][d] = sum;
};

void solve(){
    string a, b; cin >> a >> b;

    if (b == "0"){
        cout << "1"; return;
    }
    
    memo = vector <array <int, 12>> (b.length() + 1);
    int big = f(b, 0, 10);

    memo = vector <array <int, 12>> (a.length() + 1);
    int smol = f(a, 0, 10);

    int adder = 1;
    for(int i = 1; i < a.length(); ++i){
        if (a[i] == a[i - 1]){
            adder = 0; break;
        }
    }

    cout << big - smol + adder + (a == "0") ;
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
}