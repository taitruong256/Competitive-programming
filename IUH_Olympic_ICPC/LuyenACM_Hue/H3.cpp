/*=====================================================================================
                Nothing is impossible, only you think it is impossible                 
                        Try, try, try again until you succeed     
                           Pratice, practice, and practice
I hated every minute of training, but I said, ‘Don’t quit. Suffer now and live the rest of your life as a champion.' - Mohamed Ali 
=====================================================================================*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
struct diem { ll x ,y; };

bool thuoc_doan(ll x1, ll y1, ll x2, ll y2, ll x3, ll y3)
{
    ll a=y1-y2;
    ll b=x2-x1;
    x1=-x1;
    y1=-y1;
    ll c=a*x1+b*y1;
    ll t=a*x3+b*y3+c;
    if (t==0) return true;
    return false;
}

double S_tamgiac(vector<diem> v)
{
    ll a=v[1].x-v[0].x;
    ll b=v[1].y-v[0].y;
    ll c=v[2].x-v[0].x;
    ll d=v[2].y-v[0].y;
    return (0.5*(abs(a*d-b*c)));
}

void solve()
{
    ll n, q; cin>>n>>q;
    vector<diem> dagiac;
for (ll i=1; i<=n; i++)
{
    ll x, y; cin>>x>>y;
    dagiac.push_back({x, y});
}
    dagiac.push_back(dagiac[0]);

    double sum=0;
    for(int i=0;i<dagiac.size()-1;i++)
        sum+=dagiac[i].x*dagiac[i+1].y - dagiac[i].y*dagiac[i+1].x;
    sum=fabs(sum)/2;
    //printf("%lf\n", sum);
    
    for (ll i=0; i<q; i++)
    {
        double s=0;
        ll x, y; cin>>x>>y;
        vector<diem> p;
        for (ll j=0; j<n; j++)
        {
            p.clear();
            p.push_back({x, y});
            for (ll k=j; k<j+2; k++)
                p.push_back(dagiac[k]);
            s+=S_tamgiac(p);
        }

        if (fabs(sum-s)>0.000000001)
        {
            cout<<"OUTSIDE\n";
        }
        else
        {
            bool ok=false;
            for (ll i=0; i<n; i++) if (thuoc_doan(dagiac[i].x, dagiac[i].y, dagiac[i+1].x, dagiac[i+1].y, x, y)==true)
            {
                cout<<"BOUNDARY\n";
                ok=true;
                break;
            }
            if (ok==false) cout<<"INSIDE\n";
        }
        //printf("%lf\n", s);
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