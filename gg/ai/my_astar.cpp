#include<bits/stdc++.h>
using namespace std;

vector<vector<int>>ist,gst;
map<vector<vector<int>>,int>mp;


void solve(vector<vector<vector<int>>> &v,int k){
    vector<vector<vector<int>>> pa1;
    vector<pair<int,vector<vector<int>>>>vp;


    for(int il=0;il<v.size();il++){
        vector<vector<int>>v1 = v[il];
        if(v1==gst){
            cout<<"Goal state reached in "<< k-1 <<" steps"<<endl;
            return;
        }
        int x1,y1;
        for(int i=0;i<3;i++){
            for(int j=0;j<3;j++){
                if(v1[i][j]==-1){
                    x1 = i;
                    y1 = j;
                }
            }
        }

        int h;
        cout<<"States after step"<<" "<<k<<" "<<"are:"<<endl;
        //moving up
        if(x1-1>=0){
            v1[x1][y1] = v1[x1-1][y1];
            v1[x1-1][y1] = -1;

            h=0;
            for(int i=0;i<3;i++){
                for(int j=0;j<3;j++){
                    cout<<v1[i][j]<<" ";
                    if(v1[i][j]==-1){}
                    else if(v1[i][j]!=gst[i][j])h++;
                }
                cout<<endl;
            }

            if(mp[v1]==0){
                mp[v1]++;
                vp.push_back({k+h,v1});
            }
            else cout<<"The state is repeating!!!!!"<<endl;
            v1[x1-1][y1] = v1[x1][y1];
            v1[x1][y1] = -1;
            cout<<"g(n) = "<<k<<endl;
            cout<< "h(n) = "<<h<<endl;
            cout<<"f(n) = "<<k+h<<endl;
        } cout<<endl;

        //moving down
        if(x1+1<3){
            v1[x1][y1] = v1[x1+1][y1];
            v1[x1+1][y1] = -1;

            h=0;
            for(int i=0;i<3;i++){
                for(int j=0;j<3;j++){
                    cout<<v1[i][j]<<" ";
                    if(v1[i][j]==-1){}
                    else if(v1[i][j]!=gst[i][j])h++;
                }
                cout<<endl;
            }

            if(mp[v1]==0){
                mp[v1]++;
                vp.push_back({k+h,v1});
            }
            else cout<<"The state is repeating!!!!!"<<endl;
            v1[x1+1][y1] = v1[x1][y1];
            v1[x1][y1] = -1;
            cout<<"g(n) = "<<k<<endl;
            cout<< "h(n) = "<<h<<endl;
            cout<<"f(n) = "<<k+h<<endl;
        }
        cout<<endl;

        //moving left
        if(y1-1>=0){
            v1[x1][y1] = v1[x1][y1-1];
            v1[x1][y1-1] = -1;

            h=0;
            for(int i=0;i<3;i++){
                for(int j=0;j<3;j++){
                    cout<<v1[i][j]<<" ";
                    if(v1[i][j]==-1){}
                    else if(v1[i][j]!=gst[i][j])h++;
                }
                cout<<endl;
            }

            if(mp[v1]==0){
                mp[v1]++;
                vp.push_back({k+h,v1});
            }
            else cout<<"The state is repeating!!!!!"<<endl;
            v1[x1][y1-1] = v1[x1][y1];
            v1[x1][y1] = -1;
            cout<<"g(n) = "<<k<<endl;
            cout<< "h(n) = "<<h<<endl;
            cout<<"f(n) = "<<k+h<<endl;
        }

        cout<<endl;
        //moving right
        if(y1+1<3){
            v1[x1][y1] = v1[x1][y1+1];
            v1[x1][y1+1] = -1;

            h=0;
            for(int i=0;i<3;i++){
                for(int j=0;j<3;j++){
                    cout<<v1[i][j]<<" ";
                    if(v1[i][j]==-1){}
                    else if(v1[i][j]!=gst[i][j])h++;
                }
                cout<<endl;
            }

            if(mp[v1]==0){
                mp[v1]++;
                vp.push_back({k+h,v1});
            }
            else cout<<"The state is repeating!!!!!"<<endl;
            v1[x1][y1+1] = v1[x1][y1];
            v1[x1][y1] = -1;
            cout<<"g(n) = "<<k<<endl;
            cout<< "h(n) = "<<h<<endl;
            cout<<"f(n) = "<<k+h<<endl;
        }
    }
    if(vp.size()==0){
        cout<<"NO SOLUTION!!!!"<<endl;
        return ;
    }
    sort(vp.begin(),vp.end());
    pa1.push_back(vp[0].second);
    for(int i=1;i<vp.size();i++){
        if(vp[i].first == vp[i-1].first) pa1.push_back(vp[i].second);
        else break;
    }
    cout<<endl;
    cout<<"-------------------------------------------------------------"<<endl;
    cout<<"State with minimum heuristic value:"<<endl;

    for(int i=0;i<pa1.size();i++){
        vector<vector<int>>curr = pa1[i];
        for(int i=0;i<3;i++){
            for(int j=0;j<3;j++){
                cout<<curr[i][j]<<" ";
            }
            cout<<endl;
        }
        cout<<endl;
        cout<<"f(n) = "<<vp[i].first<<endl;
    }

    solve(pa1,k+1);
}

int main(){
    cout<<"Enter initial state: "<<endl;
    
    for(int i=0;i<3;i++){
        vector<int>temp;
        for(int j=0;j<3;j++){
            int x;
            cin>>x;
            temp.push_back(x);
        }
        ist.push_back(temp);
    }

    cout<<"Enter goal state: "<<endl;
    for(int i=0;i<3;i++){
        vector<int>temp;
        for(int j=0;j<3;j++){
            int x;
            cin>>x;
            temp.push_back(x);
        }
        gst.push_back(temp);
    }
    vector<vector<vector<int>>>pa;
    pa.push_back(ist);
    int k=1;
    cout<<"-------------------------------------------"<<endl;
    solve(pa,k);
    return 0;
}