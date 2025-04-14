#include<bits/stdc++.h>
#define ll long long
using namespace std;

void solve()
{
    ll a, b; cin>>a>>b; 
    if (b==0 ) 
    {
        cout<<1<<endl;
        return;
    }
    if(a%10==0) {
        cout<<0<<endl;
        return ;
    }
    vector<ll>v;
    v.push_back(int(pow(a,0))%10);
    v.push_back(int(pow(a,1))%10);
    v.push_back(int(pow(a,2))%10);
    v.push_back(int(pow(a,3))%10);
    v.push_back(int(pow(a,4))%10);
    cout<<v[b%4];       cout<<endl;

}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    #ifndef ONLINE_JUDGE
    freopen("_input.txt", "r", stdin);
    freopen("_output.txt", "w", stdout);
    #endif
    solve();
    return 0;
}