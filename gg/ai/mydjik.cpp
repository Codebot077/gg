#include<bits/stdc++.h>
using namespace std;

int main(){
    int n,m;
    cin>>n>>m;

    vector<vector<int>>v[n];

    for(int i=0;i<m;i++){
        int a,b,c;
        cin>>a>>b>>c;
        v[a].push_back({b,c});
        v[b].push_back({a,c});
    }
    set<vector<int>>st;
    st.insert({0,1});
    vector<int>dist(n+1,INT_MAX);
    dist[1] =0;
    int ans = 0;

    while(!st.empty()){
        auto u=*st.begin();
        int wt = u[0];
        int node = u[1];
        st.erase(u);
        for(auto it:v[node]){
            if(it[1]+wt<dist[it[0]]){
                dist[it[0]] = it[1]+wt;
                st.insert({dist[it[0]],it[0]});
            }
        }
    }
    for(int i = 0;i<n;i++){
        cout<<i<<" : "<<dist[i]<<endl;
    }
}