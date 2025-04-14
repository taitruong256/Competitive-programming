#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve()
{
    ll n=5;
    double thoigian[10], wrong[10],diem[10];
    diem[1]=500;
    diem[2]=1000;
    diem[3]=1500;
    diem[4]=2000;
    diem[5]=2500;
    for (ll i=1; i<=5; i++) cin>>thoigian[i];
    for (ll i=1; i<=5; i++) cin>>wrong[i];
    ll a, b; cin>>a>>b;
    double ans=0, sum=0;
    for (ll i=1; i<=5; i++) ans+=max((0.3*diem[i]), (250.0-thoigian[i])/250*diem[i]-wrong[i]*50);
    ans=max(0.0, ans+100*a-50*b);
    cout<<ans<<endl;
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    #ifndef ONLINE_JUDGE
    freopen("_input.txt", "r", stdin);
    freopen("_output.txt", "w", stdout);
    #endif // ONLINE_JUDGE
    solve();
    return 0;
}
