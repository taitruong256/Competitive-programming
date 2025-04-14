/*=====================================================================================
                Nothing is impossible, only you think it is impossible                 
                        Try, try, try again until you succeed     
                           Pratice, practice, and practice
I hated every minute of training, but I said, ‘Don’t quit. Suffer now and live the rest of your life as a champion.' - Mohamed Ali 
=====================================================================================*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
struct block {
    string d1,d2,d3,d4,d5;
}A,B,C,D,E;
void solve()
{
    ll n; cin>>n;
    A.d1="***";
    A.d2="*.*";
    A.d3="***";
    A.d4="*.*";
    A.d5="*.*";
    B.d1="***";
    B.d2="*.*";
    B.d3="***";
    B.d4="*.*";
    B.d5="***";
    C.d1="***";
    C.d2="*..";
    C.d3="*..";
    C.d4="*..";
    C.d5="***";
    D.d1="***";
    D.d2="*.*";
    D.d3="*.*";
    D.d4="*.*";
    D.d5="***";
    E.d1="***";
    E.d2="*..";
    E.d3="***";
    E.d4="*..";
    E.d5="***";
    string s; cin>>s;
    string a[5];
    for(int i=0;i<s.size();i++){
        if (s[i]=='A'){
            a[0]+=A.d1;
            a[1]+=A.d2;
            a[2]+=A.d3;
            a[3]+=A.d4;
            a[4]+=A.d5;

        } 
        if (s[i]=='B'){
            a[0]+=B.d1;
            a[1]+=B.d2;
            a[2]+=B.d3;
            a[3]+=B.d4;
            a[4]+=B.d5;

        }
        if (s[i]=='C'){
            a[0]+=C.d1;
            a[1]+=C.d2;
            a[2]+=C.d3;
            a[3]+=C.d4;
            a[4]+=C.d5;

        }

        if (s[i]=='D'){
            a[0]+=D.d1;
            a[1]+=D.d2;
            a[2]+=D.d3;
            a[3]+=D.d4;
            a[4]+=D.d5;

        }
        if (s[i]=='E'){
            a[0]+=E.d1;
            a[1]+=E.d2;
            a[2]+=E.d3;
            a[3]+=E.d4;
            a[4]+=E.d5;

        }
    }
    for(int i=0;i<5;i++){
        cout<<a[i]<<"\n";
    }



    

}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    #ifndef ONLINE_JUDGE
    freopen("_input.txt", "r", stdin);
    freopen("_output.txt", "w", stdout);
    #endif
     solve();
    return 0;
}