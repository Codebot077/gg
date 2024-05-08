#include <iostream>
#include <bits/stdc++.h>
#include <cmath>

using namespace std;

int modpow(int a, int b, int M) {
    int result = 1;
    while(b--){
        result*=a;
        result%=M;
    }
    return result;
}

int main() {
    // Prime numbers
    int p = 61;
    int q = 53;

    int n = p * q;
    int phi = (p - 1) * (q - 1);

    // Public exponent
    int e = 11; // Commonly used value (1<e<phi)

    // Private exponent
    int d = 0;
    while (true) {
        if ((e * d) % phi == 1)
            break;
        d++;
    }

    // Message to be encrypted
    int msg = 1111;

    // Encryption
    int c = modpow(msg, e, n);

    // Decryption
    int m = modpow(c, d, n);

    cout << "Message data = " << msg << endl;
    cout << "p = " << p << endl;
    cout << "q = " << q << endl;
    cout << "n = pq = " << n << endl;
    cout << "totient = " << phi << endl;
    cout << "e = " << e << endl;
    cout << "d = " << d << endl;
    cout << "Encrypted data = " << c << endl;
    cout << "Original Message sent = " << m << endl;

    return 0;
}