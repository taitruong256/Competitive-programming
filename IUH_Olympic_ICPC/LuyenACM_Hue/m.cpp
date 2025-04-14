#include<bits/stdc++.h>
#define ll long long
using namespace std;

void solve()
{
    ll a, b; cin>>a>>b; 
    if (b==0 ) 
    {
        cout<<1;               cout<<endl;
        return;
    }
    if(a==0) {
        cout<<0;              cout<<endl;
        return ;
    }
    vector<ll>v;
    v.push_back((ll)(pow(a,1))%10);
    v.push_back((ll)(pow(a,2))%10);
    v.push_back((ll)(pow(a,3))%10);
    v.push_back((ll)(pow(a,4))%10);
    b%=4;
    if (b==0) cout<<v[3];
    else cout<<v[b-1];               cout<<endl;
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    #ifndef ONLINE_JUDGE
    freopen("_input.txt", "r", stdin);
    freopen("_output.txt", "w", stdout);
    #endif
    ll t; cin>>t;
    while (t--)
    solve();
    return 0;
}
