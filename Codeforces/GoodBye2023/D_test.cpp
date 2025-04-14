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
                                          Done is better than perfect
                                         Pain + Reflection = Progress 
==============================================================================================================*/
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
#define endl '\n'
const ll mod = 1e9+7;

bool chinhphuong(string x)
{
    ll n=0;
    for (ll i=x.size()-1; i>=0; i--) n=(n*10)+x[i]-'0';
    ll d=sqrt(n);
    if (d*d==n) return true;
    return false;
}

void solve()
{

    // set<string> st1;
    // for (ll i=1; i<=9; i++)
    //     for (ll j=1; j<=9; j++)
    //         for (ll k=1; k<=9; k++)
    //         {
    //             ll x=i*100+j*10+k;
    //             string s=to_string(x);
    //             sort(s.begin(), s.end());
    //             ll cnt=0;
    //             do 
    //             {
    //                 cnt+=chinhphuong(s);
    //             }
    //             while (next_permutation(s.begin(), s.end()));
    //             if (cnt>=3) st1.insert(s);
    //         }
    // for (auto i: st1) cout<<i<<endl;

    // set<string> st2;
    // for (ll a=1; a<=9; a++)
    //     for (ll b=1; b<=9; b++)
    //         for (ll c=1; c<=9; c++)
    //             for (ll d=1; d<=9; d++)
    //                 for (ll e=1; e<=9; e++)
    //                 {
    //                     ll x=a*10000+b*1000+c*100+d*10+e;
    //                     string s=to_string(x);
    //                     sort(s.begin(), s.end());
    //                     ll cnt=0;
    //                     do 
    //                     {
    //                         cnt+=chinhphuong(s);
    //                     }
    //                     while (next_permutation(s.begin(), s.end()));
    //                     if (cnt>=5) st2.insert(s);
    //                 }
    // for (auto i: st2) cout<<i<<endl;

    // for (ll a=1; a<=9; a++)
    //     for (ll b=1; b<=9; b++)
    //         for (ll c=1; c<=9; c++)
    //             for (ll d=1; d<=9; d++)
    //                 for (ll e=1; e<=9; e++)
    //                     for (ll f=1; f<=9; f++)
    //                         for (ll g=1; g<=9; g++)
    //                         {
    //                             ll x=a*1000000+b*100000+c*10000+d*1000+e*100+f*10+g;
    //                             string s=to_string(x);
    //                             sort(s.begin(), s.end());
    //                             ll cnt=0;
    //                             do 
    //                             {
    //                                 cnt+=chinhphuong(s);
    //                             }
    //                             while (next_permutation(s.begin(), s.end()));
    //                             if (cnt>=7) cout<<s<<endl;
    //                             if (x>2e7) break;
    //                         }
    
    bool check=false;
    for (ll a=1; a<=9 && check==false; a++)
        for (ll b=1; b<=9 && check==false; b++)
            for (ll c=1; c<=9 && check==false; c++)
                for (ll d=1; d<=9 && check==false; d++)
                    for (ll e=1; e<=9 && check==false; e++)
                        for (ll f=1; f<=9 && check==false; f++)
                            for (ll g=1; g<=9 && check==false; g++)
                                for (ll h=1; h<=9; h++)
                                    for (ll i=1; i<=9; i++)
                                    {
                                        ll x=a*100000000+b*10000000+c*1000000+d*100000+e*10000+f*1000+g*100+h*10+i;
                                        string s=to_string(x);
                                        sort(s.begin(), s.end());
                                        ll cnt=0;
                                        do 
                                        {
                                            cnt+=chinhphuong(s);
                                        }
                                        while (next_permutation(s.begin(), s.end()));
                                        if (cnt>=9) 
                                        {
                                            cout<<s<<endl, check=true;
                                            return;
                                        }
                                    }

}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    clock_t start = clock();
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    solve();
    clock_t end = clock();
    cerr<<"Time: "<<fixed<<setprecision(10)<<double(end-start)/double(CLOCKS_PER_SEC)<<"\n";
    return 0;
}