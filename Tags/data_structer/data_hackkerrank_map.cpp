#include<bits/stdc++.h>
using namespace std;


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    #ifndef ONLINE_JUDGE
    freopen("_input.txt","r",stdin);
    freopen("_output.txt", "w", stdout);
    #endif
    map<string, string> phone;  
    int n; cin>>n;
    string s, x;      
    for (int i=0; i<n; i++)
    {
        cin.ignore();
        cin>>s>>x;  
        phone[s]=x;
    } 
    while (true)
    {
        cin.ignore();
        string s; cin>>s; 
        if (s=="") break;
        if (phone[s]!="") cout<<s<<"="<<phone[s]<<endl;
        else cout<<"Not found\n";
    }
    
    return 0;
}
