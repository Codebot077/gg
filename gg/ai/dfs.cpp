#include<bits/stdc++.h>
using namespace std;

const int N=1e5+10;

// vecto<int> g[N];
// vector<int>vis(N,0);
// void dfs(int vertex, int limit){
//     if(vis[vertex]) return;
//     if(limit==0) return;
//     cout<<vertex<<" ";
//     vis[vertex]=1;
//     for(auto child:g[vertex]) dfs(child,limit-1);
//     return;
// }
vector<int> g[N];
bool vis1[N];
bool vis2[N];
bool vis3[N];
int level[N];


void dfs(int vertex){
	cout << vertex << endl;
	vis1[vertex]=true;
	for(int child : g[vertex]){
		if (!vis1[child]) {
            dfs(child);
        }
	}
}

void bfs(int source){
	queue<int> q;
	q.push(source);
	vis2[source]=1;
	while(!q.empty()){
		int curr = q.front();
		q.pop();
		cout << curr << endl;
		for(int child:g[curr]){
			if(!vis2[child]){
				q.push(child);
				vis2[child]=true;
				level[child]=level[curr]+1;
			}
		}
	}
}

void dls(int source, int height){
	queue<int> q;
	q.push(source);
	vis3[source] = true;
	while(!q.empty()){
		int curr = q.front();
		q.pop();
		cout << curr << endl;
		for(int child:g[curr]){
			if(!vis3[child] and level[child]<height){
				q.push(child);
				vis3[child]=true;
			}
		}
	}
}

int main(){
	int n, m;
	cout << "Enter the no. of nodes and edges" << endl;
	cin >> n >> m;
	cout << "Enter the edges " << endl;
	for(int i=0;i<m;i++){
		int v1, v2;
		cin >> v1 >> v2;
		g[v1].push_back(v2);
		g[v2].push_back(v1);
	}
	int source;
	cout << "Enter source vertex" << endl;
	cin >> source;
	int height;
	cout << "Enter the height" << endl;
	cin >> height;
	cout << "dfs" << endl;
	dfs(source);
	cout << "bfs" << endl; 
	bfs(source);
	cout << "dls" << endl;
	dls(source, height);
}