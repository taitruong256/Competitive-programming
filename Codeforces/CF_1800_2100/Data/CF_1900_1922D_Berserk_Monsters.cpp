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

/*
Ban đầu có n quái vật, mỗi quái vật có sức tấn công a[i], phòng thủ d[i].
Có n vòng:
    -Đầu tiên mỗi quái vật còn sống gây ra a[i] sát thương cho 2 quái vật liền trái và liền phải.
    -Nếu quái vật i nhận nhiều sát thương hơn d[i], nó sẽ chết.
Mỗi vòng hãy tính số quái vật bị giết.

Input
3
5
3 4 7 5 10
4 9 1 18 1
2
2 1
1 3
4
1 1 2 4
3 3 4 2
Output
3 1 0 0 0 
0 0 
1 1 1 0 

Explanation for the first test case of the example:

During the first round, the following happens:
the monster 1 deals 3 damage to the monster 2;
the monster 2 deals 4 damage to the monster 1 and the monster 3;
the monster 3 deals 7 damage to the monster 2 and the monster 4;
the monster 4 deals 5 damage to the monster 3 and the monster 5;
the monster 5 deals 10 damage to the monster 4;
the monster 1 does not die, since it received 4 damage and its defense is 4;
the monster 2 dies, since it received 10 damage and its defense is 9;
the monster 3 dies, since it received 9 damage and its defense is 1;
the monster 4 does not die, since it received 17 damage and its defense is 18;
the monster 5 dies, since it received 5 damage and its defense is 1.
After the first round, the monsters 1 and 4 stay alive.

During the second round, the following happens:

the monster 1 deals 3 damage to the monster 4;
the monster 4 deals 5 damage to the monster 1;
the monster 1 dies, since it received 5 damage and its defense is 4;
the monster 4 does not die, since it received 3 damage and its defense is 18.
During the next three rounds, only the 4-th monster is alive, so nothing happens.

Ý tưởng:
Nhận xét quan trọng là nếu vòng thứ j quái vật i không chết và hai quái vật liền kề không chết thì không ảnh hưởng gì
tới vòng thứ j+1.
Vì không nhiều hơn 2 quái vật được thêm vào nên tổng ứng viên của n vòng không vượt quá 3n.
Ta chỉ cần duy trì một tập các ứng cử viên cho mỗi vòng. Nếu vòng thứ j quái vật i bị giết thì thêm 2 quái vật liền kề
vào danh sách ứng viên. 
*/

void solve()
{
    ll n; cin>>n;
    ll a[n+5], d[n+5];
    for (ll i=1; i<=n; i++) cin>>a[i];
    for (ll i=1; i<=n; i++) cin>>d[i];

    set<ll> killed, alives;
    for (ll i=1; i<=n; i++) alives.insert(i);
    auto check = [&](ll x) -> bool 
    {
        auto l=alives.lower_bound(x);
        auto r=alives.upper_bound(x);
        ll damages=0;
        if (l!=alives.begin()) damages+=a[*(--l)];
        if (r!=alives.end()) damages+=a[*r];
        if (damages>d[x]) return true;
        return false;
    };
    for (ll i=1; i<=n; i++) if (check(i)==true) killed.insert(i);
    for (ll i=1; i<=n; i++)
    {
        cout<<killed.size()<<" ";
        for (ll i: killed) alives.erase(i);
        set<ll> newkilled;
        for (ll i: killed) 
        {
            auto l=alives.lower_bound(i);
            auto r=alives.upper_bound(i);
            if (l!=alives.begin() && check(*(--l))==true) newkilled.insert(*l);
            if (r!=alives.end() && check(*r)==true) newkilled.insert(*r);
        }
        killed=newkilled;
    }
    cout<<endl;
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    clock_t start = clock();
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    ll t; cin>>t;
    while (t--) solve();
    clock_t end = clock();
    cerr<<"Time: "<<fixed<<setprecision(10)<<double(end-start)/double(CLOCKS_PER_SEC)<<"\n";
    return 0;
}