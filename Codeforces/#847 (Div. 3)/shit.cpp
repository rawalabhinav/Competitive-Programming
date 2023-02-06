#include <bits/stdc++.h>

signed main(){
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    auto solve = [&](){
            int n; std::cin>>n;
            std::string in;
            std::cin>>in;
     
            while(in[0] != in[std::max(0,(int) in.length() - 1)]) {
                in.pop_back();
                in.erase(in.begin());
            }
            std::cout<<in.length()<<'\n';
        };
        
    int t; std::cin >> t;
    for(; t; --t) solve();
}