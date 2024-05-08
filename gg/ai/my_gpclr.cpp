#include<bits/stdc++.h>
using namespace std;

const int N = 2e5;
vector<int> graph[N];


int main(){
    cout<<"Enter number of vertex and edges:"<<endl;
    int n,m;
    cin>>n>>m;

    cout<<"Enter edges:"<<endl;
    for(int i=0;i<m;i++){
        int a,b;
        cin>>a>>b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    vector<int>color(n,-1);
    vector<int>used(n,-1);
    color[0] = 0;
    set<int>st;

    for(int i=1;i<n;i++){
        for(auto it:graph[i]){
            if(color[it]!=-1){
                used[color[it]]=1;
            }
        }
        int clr;

        for(clr=0;clr<n;clr++){
            if(used[clr]==-1)break;
        }

        color[i] =clr;
        st.insert(clr);
        for(auto it:graph[i]){
            if(color[it]!=-1){
                used[color[it]]=-1;
            }
        }
    }

    cout<<"Vertex\t"<<"Color"<<endl;
    for(int i=0;i<n;i++){
        cout<<i<<"\t"<<color[i]<<endl;
    }

    cout<<"Total color used: "<<st.size();
}