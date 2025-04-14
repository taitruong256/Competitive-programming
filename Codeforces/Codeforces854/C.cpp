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
I hated every minute of training, but I said, ‘Don’t quit. Suffer now and live the rest of your life as a champion.' - Mohamed Ali 
                              You may not be the best, but must be the most effort
==============================================================================================================*/
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
const ll mod = 1e9+7;

void solve()
{
    string s; cin>>s;
    if (s.size()==1) 
    {
        cout<<s<<endl;
        return;
    }
    else if (s.size()==2)
    {
        sort(s.begin(), s.end(), greater<char>());
        cout<<s<<endl;
        return;
    }



    sort(s.begin(), s.end());
    deque<char> left, right, left2, right2;
    ll n=s.size();
    deque<char> dq, dq2;
    for (ll i=0; i<n; i++) dq.push_back(s[i]);
    while (dq.size()>0)
    {
        if (dq.size()==1) 
        {
            left.push_back(dq.front());
            dq.pop_front();
        }
        else 
        {
            if (dq[0]==dq[1])
            {
                left.push_back(dq.front()); dq.pop_front();
                right.push_front(dq.front()); dq.pop_front();
            }
            else 
            {
                dq2=dq, left2=left, right2=right;
                char x=dq.front(); dq.pop_front();
                char y=dq.front();
                while (dq.size()>=2 && dq[0]==y && dq[0]==dq[1]) 
                {
                    left.push_back(dq.front()); dq.pop_front();
                    right.push_front(dq.front()); dq.pop_front();
                }
                sort(dq.begin(), dq.end());
                left.push_back(x);
                while (dq.size()>0)
                {
                    right.push_front(dq.front()); 
                    dq.pop_front();
                }

                //-------------------------------------

                x=dq2.front(); dq2.pop_front();
                y=dq2.front(); dq2.pop_front();
                dq2.push_front(y);
                sort(dq2.begin(), dq2.end());
                left2.push_back(x);
                while (dq2.size()>0)
                {
                    right2.push_front(dq2.front()); 
                    dq2.pop_front();
                }
            }
        }
    }
    reverse(left.begin(), left.end());
    reverse(right.begin(), right.end());
    reverse(left2.begin(), left2.end());
    reverse(right2.begin(), right2.end());
    string ans1, ans2;
    for (auto i: right) ans1.push_back(i);
    for (auto i: left) ans1.push_back(i);
    for (auto i: right2) ans2.push_back(i);
    for (auto i: left2) ans2.push_back(i);
    cout<<ans1<<" "<<ans2<<endl;
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    clock_t start = clock();
    #ifndef ONLINE_JUDGE
    freopen("_input.txt", "r", stdin);
    freopen("_output.txt", "w", stdout);
    #endif
    ll t; cin>>t;
    while (t--) solve();
    clock_t end = clock();
    cerr<<"Time: "<<fixed<<setprecision(10)<<double(end-start)/double(CLOCKS_PER_SEC)<<"\n";
    return 0;
}