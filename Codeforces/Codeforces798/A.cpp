/*=====================================================================================
                Nothing is impossible, only you think it is impossible                 
                        Try, try, try again until you succeed     
                           Pratice, practice, and practice
I hated every minute of training, but I said, ‘Don’t quit. Suffer now and live the rest of your life as a champion.' - Mohamed Ali 
                  You may not be the best, but must be the most effort
=====================================================================================*/
#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define ll long long

void solve()
{
    ll n, m, k; cin>>n>>m>>k;
    string s, t; cin>>s>>t;
    sort(s.begin(), s.end(), greater<char>());
    sort(t.begin(), t.end(), greater<char>());
    fflush(stdin);
    // cout<<s<<endl<<t<<endl;
    string ans;
    ll a=0, b=0;
    // if (k==1)
    // {
       
    //     string ans1, ans2;
    //     for (int i=0; i<min(s.size(), t.size()); i++)
    //     {
    //         if (i%2==0)
    //         {
    //             ans1.push_back(s.back());
    //             ans1.push_back(t.back());
    //             s.pop_back();
    //             t.pop_back();
    //         }
    //         else
    //         {
    //             ans1.push_back(t.back());
    //             ans1.push_back(s.back());
    //             s.pop_back();
    //             t.pop_back();
    //         }
    //     }
    //     for (int i=0; i<min(s.size(), t.size()); i++)
    //     {
    //         if (i%2==0)
    //         {
    //             ans2.push_back(t.back());
    //             ans2.push_back(s.back());
    //             s.pop_back();
    //             t.pop_back();
    //         }
    //         else
    //         {
    //             ans2.push_back(s.back());
    //             ans2.push_back(t.back());
    //             s.pop_back();
    //             t.pop_back();
    //         }
    //     }
    //     cout<<min(ans1, ans2)<<endl;
    //     return;
    // }

    while (s.size()>0 && t.size()>0)
    {
        if (s.back()<t.back() && a<k)
        {
            ++a;
            ans.push_back(s.back());
            s.pop_back();
            b=0;
        }
        else if (b<k)
        {
            ++b;
            ans.push_back(t.back());
            t.pop_back();
            a=0;
        }
        else 
        {
            ++a;
            ans.push_back(s.back());
            s.pop_back();
            b=0;
        }
        // cout<<a<<" "<<b<<endl;
    }
    cout<<ans<<endl;
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    #ifndef ONLINE_JUDGE
    freopen("_input.txt", "r", stdin);
    freopen("_output.txt", "w", stdout);
    #endif
    ll t; cin>>t;
    while (t--) solve();
    return 0;
}