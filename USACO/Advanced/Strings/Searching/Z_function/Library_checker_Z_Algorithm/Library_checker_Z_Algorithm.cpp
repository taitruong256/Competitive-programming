/*==============================================================================================================
         __                    __                                             _____     ______    _______
        |  |                  |  |                                           /  __ \   / _____|  / ______|     
      __|  |__              __|  |__                                         |_|  | |  | |       | |  
     |__|   __|            |__|   __|                                             | |  | |____   | |_____ 
        |  |    _____   _     |  |    ____  __  __  ____    _____    _____       / /   \ ___  \  |  ___  \
        |  |   /  _  \ | |    |  |   /  _/ | | | | /  _  \ /  __ \  /  _  \     / /         | |  | |   | |
        |  |_  | |_| | | |    |  |_  | |   | |_| | | |_| | | |  | | | |_| |    / /___   ____| |  | |___| |
        \____\ \____/| |_|    \____\ |_|   \_____/ \_____/ |_|  |_| \____ |   |______| |______/  \_______/
                                                                        | |
                                                                      __/ |
                                                                     |___/  
                                        Pratice, practice, and practice
                                       Where is the bug, delete it there
                                     Try, try, try again until you succeed
I hated every minute of training, but I said, 'Don't quit. Suffer now and live the rest of your life as a champion.' - Mohamed Ali 
                              You may not be the best, but must be the most effort
     Even the things and people you like, you don't have the courage to take, you are destined to be a failure.
                                           Difficult means more time
                                         Pain + Reflection = Progress 
==============================================================================================================*/
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
#define endl '\n'
const ll mod = 1e9+7;
const ll inf = 1e18;

struct Z_function
{
    vector<ll> z; // z[i]=do dai tien to dai nhat cua s va s[i: n-1]
    ll n, l, r;
    string s;

    Z_function(){}
    Z_function(string _s)
    {
        s=_s;
        n=_s.size();
        z.resize(n+5);
        z[0]=n;  //tuy bai toan ma z[0]=0;
        l=0; r=0;  //duy tri doan s[l, r)=s[0:r-l) da duoc tinh. z[i]=r-l 
        for (ll i=1; i<n; i++)
        {
            if (i<r) z[i]=min(z[i-l], r-i);  //lay min (z[i-l], r-i) vi z[i-l] co the lon hon r-i vo ly
            while (i+z[i]<n && s[z[i]]==s[i+z[i]]) ++z[i];  //thuat toan tam thuong 
            if (i+z[i]>r) l=i, r=i+z[i];  //cap nhat doan [l, r)=[i, i+z[i])
        }
    }
};

void solve()
{
    string s; cin>>s;
    Z_function zf(s);
    for (ll i=0; i<s.size(); i++) cout<<zf.z[i]<<" ";
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    clock_t start = clock();
    #ifndef ONLINE_JUDGE
    freopen("_input.txt", "r", stdin);
    freopen("_output.txt", "w", stdout);
    #endif
    solve();
    clock_t end = clock();
    cerr<<"Time: "<<fixed<<setprecision(10)<<double(end-start)/double(CLOCKS_PER_SEC)<<"\n";
    return 0;
}