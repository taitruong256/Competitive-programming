//Đây là file ví dụ
#include<bits/stdc++.h>
using namespace std;

const int Jury_n = 3;
int get_N() {
    return Jury_n;
}
int guess(int k) {
    if (k < 0 || k > Jury_n)
        return 0;
    return 1;   
}
