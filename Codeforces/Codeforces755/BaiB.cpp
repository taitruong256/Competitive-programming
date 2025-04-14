#include<bits/stdc++.h>
using namespace std;

 int main()
 {
     int t;
     t=1; cin>>t;
     while (t--)
     {
         int n, m;
         cin>>n>>m;
         cout<<min(n, m)+max(n, m)/2<<endl;
     }
     return 0;
 }
