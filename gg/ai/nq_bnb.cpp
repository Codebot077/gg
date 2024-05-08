#include<bits/stdc++.h>
using namespace std;

bool isSafe(vector<bool> &row , vector<bool> &left_digonal , vector<bool> &right_digonal , int r , int c , int n){
    if(row[r] == true or left_digonal[r+c] == true or right_digonal[c-r+n-1] == true){
        return false;
    }
    return true;
}


bool func(vector<vector<int>> &arr , int col , vector<bool> &row , vector<bool> &left_digonal , vector<bool> & right_digonal , int n){
    if(col >= arr.size()){
        return true;
    }

    for(int i=0 ; i<arr.size() ; ++i){
        if(isSafe(row , left_digonal , right_digonal , i , col , n) == true){
            row[i] =  true;
            left_digonal[i+col] = true;
            right_digonal[col-i+n-1] = true;
            arr[i][col] = 1;

            if(func(arr , col+1 , row , left_digonal , right_digonal , n) == true){
                return true;
            }

            row[i] =  false;
            left_digonal[i+col] = false;
            right_digonal[col-i+n-1] = false;
            arr[i][col] = 0;
        }
    }
    return false;
}


int main(){

    int n;
    cout << "Enter size of your Board : ";
    cin >> n;

    vector<bool> row(n , false);
    vector<bool> left_digonal(2*n-1 , false);
    vector<bool> right_digonal(2*n-1 , false);
    vector<vector<int>> arr(n , vector<int> (n , 0));
    bool flag = func(arr , 0 , row , left_digonal , right_digonal , n);

    for(int i=0 ; i<n ; ++i){
        for(int j=0 ; j<n ; ++j){
            if(arr[i][j] == 1) cout << "Q ";
            else cout << "0 ";
        }
        cout << endl;
    }
    return 0;

}