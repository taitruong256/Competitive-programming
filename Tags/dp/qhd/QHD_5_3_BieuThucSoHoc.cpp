/*=====================================================================================
                Nothing is impossible, only you think it is impossible                 
                        Try, try, try again until you succeed     
                           Pratice, practice, and practice
I hated every minute of training, but I said, ‘Don’t quit. Suffer now and live the rest of your life as a champion.'  
=====================================================================================*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
string s;
ll f[10005][10005], truoc[10005][10005];;
ll value[10005];
char dau[10005];

ll tinh(ll a, ll b, ll dau)
{
    if (dau=='+') return a+b; 
    else return a*b;
}

string truyvet(ll i, ll j)
{     //   cout<<i<<" "<<j<<endl;
    if (i==j) return to_string(value[i]);
    else if (i+1==j) return "("+to_string(value[i])+dau[i]+to_string(value[j])+")";
    else 
    {
        ll k=truoc[i][j];
        return "("+truyvet(i, k)+dau[i]+truyvet(k+1, j)+")";
    }
}

void solve()
{
    cin>>s;
    s=" "+s+"$";
    string num="";
    ll sz=s.size()-1, index=0;
    for (ll i=1; i<=sz; i++)
    {
        if (s[i]=='+' || s[i]=='x' || s[i]=='$')
        {
            ++index;
            dau[index]=s[i];
            ll x=0;
            for (ll i=0; i<num.size(); i++) x=x*10+(num[i]-'0');
            value[index]=x;
            num="";
        }
        else num+=s[i];
    }
    ll n=index;
    //for (ll i=1; i<=n; i++) cout<<value[i]<<" "<<dau[i]<<endl;

    for (ll i=0; i<=n+1; i++)
        for (ll j=0; j<=n+1; j++) f[i][j]=0;
    for (ll i=1; i<=n; i++) f[i][i]=value[i];
    for (ll i=1; i<=n-1; i++) f[i][i+1]=tinh(value[i], value[i+1], dau[i]);

    for (ll m=2; m<=n-1; m++)   //m=j-i
    {
        for (ll i=1; i<=n-m; i++)
        {
            ll j=i+m; 
            f[i][j]=-1;
            for (ll k=i; k<=j-1; k++) 
            {
                ll kq=tinh(f[i][k], f[k+1][j], dau[k]);
                if (kq>f[i][j])
                {
                    f[i][j]=kq;
                    truoc[i][j]=k;
                }
            }
        }
    }

    cout<<f[1][n]<<endl;
    cout<<truyvet(1, n);
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