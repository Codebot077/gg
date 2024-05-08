#include<bits/stdc++.h>
using namespace std;

int main() {
    string str;
    cout << "Enter your string: ";
    cout << endl;
    getline(cin, str);
    int len = str.size();
    cout << len << endl;

    string str1 = "";
    string str2 = ""; 
    string str3 = "";  

    for (int i = 0; i < len; i++) {
        int x = str[i] - '0' ^ 127;
        int y = str[i] - '0' & 127;
        int z = str[i] - '0' | 127;
        z=z-49;
        str1.push_back(x + '0');
        str2.push_back(y + '0');
        str3.push_back(z+'0');
    }


    cout << "The output of the XOR, AND, and OR are below respectively: " << endl;
    cout << "1) XOR Of the string is: " << str1 << endl;
    cout << "2) AND of the string is: " << str2 << endl;
    cout << "3) OR of the string is: " << str3 << endl;
    return 0;
}