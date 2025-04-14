/*=====================================================================================
                Nothing is impossible, only you think it is impossible                 
                        Try, try, try again until you succeed     
                           Pratice, practice, and practice
I hated every minute of training, but I said, ‘Don’t quit. Suffer now and live the rest of your life as a champion.' - Mohamed Ali 
=====================================================================================*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
bool dau[30];
char nghiem[10000];
ll n;

void in()
{
    //for (ll i=1; i<=n; i++) cout<<nghiem[i]<<" "; cout<<endl;
    cout<<nghiem<<endl;
    
    string s=nghiem;
    for (ll i=0; i<n; i++) 
    {
        char mx='0';
        ll cnt=0;
        for (ll j=i; j<i+n; j++)
        {
            if (s[j]>mx)
            {
                mx=s[j];
                ++cnt; 
            }
        }
        
        s=s+s[i-n];
        cout<<cnt<<" "; 
    }
    cout<<endl;
}

void hoanvi(ll i)
{
    for (ll j=1; j<=n; j++) if (dau[j]==false)
    {
        nghiem[i-1]=char(j+'0');
        dau[j]=true;
        if (i==n) in();
        else hoanvi(i+1);
        dau[j]=false;
    }
}


void solve()
{
    memset(dau, false, sizeof(dau));
    cin>>n;
    hoanvi(1); cout<<"    ";
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