#include<bits/stdc++.h>
using namespace std;


bool issafe(vector<vector<int>>&grid,int x,int y,int n){
    for(int row=0;row<x;row++){
        if(grid[row][y]==1) return false;
    }

    int row = x;
    int col =  y;

    while((row>=0) && (col>=0)){
        if(grid[row][col]==1) return false;
        row--;
        col--;
    }

    row = x;
    col =  y;

    while((row>=0) && (col<n)){
        if(grid[row][col]==1) return false;
        row--;
        col++;
    }

    return true;
}

bool nqueen(vector<vector<int>> &grid, int x,int n){
    if(x>=n) return true;

    for(int col =0 ; col<n;col++){
        if(issafe(grid,x,col,n)){
            grid[x][col]=1;
            if(nqueen(grid,x+1,n)){
                return true;
            }
            grid[x][col] = 0;    //Backtracking
        }
    }
    return false;
}

int main(){
    int n;
    cout<<"Enter size of grid: ";
    cin>>n;
    vector<vector<int>>grid;
    for(int i=0;i<n;i++){
        vector<int>temp;
        for(int j=0;j<n;j++){
            temp.push_back(0);
        }
        grid.push_back(temp);
    }

    if(nqueen(grid,0,n)){
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++) cout<<grid[i][j]<<" ";
            cout<<endl;
        }
    }
}