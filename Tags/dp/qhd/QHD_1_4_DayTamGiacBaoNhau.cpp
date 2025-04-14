/*=====================================================================================
                Nothing is impossible, only you think it is impossible                 
                        Try, try, try again until you succeed     
                           Pratice, practice, and practice
I hated every minute of training, but I said, ‘Don’t quit. Suffer now and live the rest of your life as a champion.'  
=====================================================================================*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n; 
struct diem{ ll x, y;};
struct tamgiac{ diem a, b, c;};
ll f[10005];
tamgiac t[10005];

double dientich(diem a, diem b, diem c)
{
    double x, y, z, p;
    x=1.0*sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y));
    y=1.0*sqrt((b.x-c.x)*(b.x-c.x)+(b.y-c.y)*(b.y-c.y));
    z=1.0*sqrt((c.x-a.x)*(c.x-a.x)+(c.y-a.y)*(c.y-a.y));
    p=(x+y+z)*0.5;
    return 1.0*sqrt(p*(p-x)*(p-y)*(p-z));
}

bool check_diem_in_tamgiac(diem p, tamgiac tg)
{
    if (1.0*dientich(p, tg.a, tg.b)+1.0*dientich(p, tg.b, tg.c)+1.0*dientich(p, tg.c, tg.a)==1.0*dientich(tg.a, tg.b, tg.c))
        return true;
    return false;
}

bool check_tamgiac_in_tamgiac(tamgiac tg1, tamgiac tg2)
{
    bool kt1=check_diem_in_tamgiac(tg1.a, tg2);
    bool kt2=check_diem_in_tamgiac(tg1.b, tg2);
    bool kt3=check_diem_in_tamgiac(tg1.c, tg2);     //     cout<<"kt = "<<kt1<<" "<<kt2<<" "<<kt3<<endl;
    return (kt1==true && kt2==true && kt3==true);
}

bool comp(tamgiac a, tamgiac b)
{
    return dientich(a.a, a.b, a.c)<dientich(b.a, b.b, b.c);
}

void solve()
{
    cin>>n;
    tamgiac abc;
    for (ll i=1; i<=n; i++) cin>>t[i].a.x>>t[i].a.y>>t[i].b.x>>t[i].b.y>>t[i].c.x>>t[i].c.y;
    sort(t+1, t+n+1, comp); 
    // for (ll i=1; i<=n; i++) 
    //     cout<<t[i].a.x<<" "<<t[i].a.y<<" "<<t[i].b.x<<" "<<t[i].b.y<<" "<<t[i].c.x<<" "<<t[i].c.y<<endl;
    for (ll i=0; i<=n+1; i++) f[i]=1;

    for (ll i=1; i<=n; i++)
    {
        for (ll j=1; j<i; j++) 
            if (check_tamgiac_in_tamgiac(t[j], t[i])==true && f[i]<f[j]+1)
                f[i]=f[j]+1;
    }

    //if (check_diem_in_tamgiac(t[9].a, t[10])) cout<<"Yes\n"; else cout<<"No\n";

    //for (ll i=1; i<=n; i++) cout<<f[i]<<" "; cout<<endl;
    ll index=0, mx=0;
    for (ll i=1; i<=n; i++) if (f[i]>mx) mx=f[i], index=i;
    cout<<f[index];
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