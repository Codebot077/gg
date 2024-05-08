#include<bits/stdc++.h>
using namespace std;

int main(){
    int n,m;
    cin>>n>>m;
    cout<<endl;
    vector<vector<int>>v[n];
    for(int i=0;i<m;i++){
        int a,b,c;
        cin>>a>>b>>c;
        v[a].push_back({b,c});
        v[b].push_back({a,c});
    }
    set<vector<int>>st;
    st.insert({0,0});
    vector<int>vis(n,0);
    int cost = 0;
    while(!st.empty()){
        auto u = *st.begin();
        int w = u[0];
        int y = u[1];
        st.erase(u);
        if(vis[y]==1) continue;
        vis[y] =1;
        cost+=w;
        for(auto it:v[y]){
            if(vis[it[0]]==0) st.insert({it[1],it[0]});
        }
    }
    cout<<cost<<endl;
}