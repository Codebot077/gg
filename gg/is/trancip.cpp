#include<bits/stdc++.h>
using namespace std;

int main(){
    string s;
    cout << "Enter your string which is to be enciphered : ";
    getline(cin , s);

    string key;
    cin >> key;

    int n = (s.size() + key.size()-1)/key.size();
    int m = key.size();
    int index = 0;

    vector<vector<char>> arr(n , vector<char> (key.size())) , brr(n , vector<char> (key.size()));
    for(int i=0 ; i<n ; ++i){
        for(int j=0 ; j<m ; ++j){
            if(index >= s.size()){
                arr[i][j] = '_';
                index++;
            }else{
                arr[i][j] = s[index];
                index++;
            }
        }
    }

    map<char , int> mp;
    for(int i=0 ; i<key.size() ; ++i) mp[key[i]] = i;

    string encrypted = "";
    for(auto it:mp){
        int x = it.second;
        for(int i=0 ; i<n ; ++i){
            encrypted += arr[i][x];
        }
    }
    cout << "Encrypted string is : " << encrypted << endl;

    index = 0;
    for(auto it:mp){
        int x = it.second;
        for(int i=0 ; i<n ; ++i){
            brr[i][x] = encrypted[index];
            index++;
        }
    }

    string decrypted = "";
    for(int i=0 ; i<n ; ++i){
        for(int j=0 ; j<m ; ++j){
            if(brr[i][j] != '_') decrypted += brr[i][j];
        }
    }

    cout << "Decrypted String is : " << decrypted << endl;
    return 0;
}