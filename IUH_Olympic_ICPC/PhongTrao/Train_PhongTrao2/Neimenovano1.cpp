
#include<bits/stdc++.h>
using namespace std;
int d, x, y;
void extendedEuclid(int A, int B) {
    if (B == 0) {
        d = A;
        x = 1;
        y = 0;
    }
    else {
        extendedEuclid(B, A%B);
        int temp = x;
        x = y;
        y = temp - (A/B)*y;
    }
}

int main() {
    extendedEuclid(3, 5);
    cout << "gcd(16, 10) = " << d << endl;
    cout << "x, y: " << x <<  ", " << y << endl;
    return 0;
}
