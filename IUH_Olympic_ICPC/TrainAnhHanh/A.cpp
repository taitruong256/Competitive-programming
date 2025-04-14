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
                             Nothing is impossible, only you think it is impossible                 
                                     Try, try, try again until you succeed     
                                        Pratice, practice, and practice
                                       Where is your bug, delete it there
I hated every minute of training, but I said, ‘Don’t quit. Suffer now and live the rest of your life as a champion.' - Mohamed Ali 
                              You may not be the best, but must be the most effort
==============================================================================================================*/
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
#define ll long long
#define ordered_set tree<ll, null_type, less<ll>, rb_tree_tag, tree_order_statistics_node_update>
#define endl '\n'
const ll mod = 1e9+7;
const ll inf = 1e9;

void solve()
{
    map<string, ll> mausac;
    mausac["Red"]=0;
    mausac["Orange"]=1;
    mausac["Yellow"]=2;
    mausac["Green"]=3;
    mausac["Blue"]=4;
    mausac["Violet"]=5;

    map<ll, string> so;
    so[0]="Red";
    so[1]="Orange";
    so[2]="Yellow";
    so[3]="Green";
    so[4]="Blue";
    so[5]="Violet";
    string s, t; cin>>s>>t;
    if (s==t) cout<<"Same";
    else if ((mausac[s]+1)%6==mausac[t]) cout<<"Adjacent";
    else if ((mausac[s]+5)%6==mausac[t]) cout<<"Adjacent";
    else if ((mausac[s]+3)%6==mausac[t]) cout<<"Complementary";
    else if ((mausac[s]+2)%6==mausac[t]) cout<<so[(mausac[s]+1)%6];
    else if ((mausac[s]+4)%6==mausac[t]) cout<<so[(mausac[s]+5)%6];
    else cout<<"None";
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    // freopen("color.inp", "r", stdin);
    // freopen("color.out", "w", stdout);
    solve();
    return 0;
}